param (
    [string]$Source,
    [string]$Destination
)

# Resolve absolute paths (safely)
$sourceItem = Get-Item -LiteralPath $Source -ErrorAction Stop
if (-not (Test-Path -LiteralPath $Destination)) {
    New-Item -ItemType Directory -Path $Destination -Force | Out-Null
    Write-Host "Created destination directory: $Destination"
}
$destinationItem = Get-Item -LiteralPath $Destination -ErrorAction Stop

$sourcePath = $sourceItem.FullName
$destinationPath = $destinationItem.FullName

# Copy non-existing files and folders
Get-ChildItem -Path $sourcePath -Recurse -Force | ForEach-Object {
    $relativePath = $_.FullName.Substring($sourcePath.Length).TrimStart('\')
    $targetPath = Join-Path $destinationPath $relativePath

    if ([string]::IsNullOrWhiteSpace($targetPath)) { return }

    try {
        if ($_.PSIsContainer) {
            if (-not (Test-Path -LiteralPath $targetPath)) {
                New-Item -ItemType Directory -Path $targetPath -Force | Out-Null
                Write-Host "Created directory: $targetPath"
            }
        } else {
            $targetDir = Split-Path -Path $targetPath -Parent
            if (-not (Test-Path -LiteralPath $targetDir)) {
                New-Item -ItemType Directory -Path $targetDir -Force | Out-Null
                Write-Host "Created directory: $targetDir"
            }
            if (-not (Test-Path -LiteralPath $targetPath)) {
                Copy-Item -Path $_.FullName -Destination $targetPath
                Write-Host "Copied file: $($_.FullName) -> $targetPath"
            }
        }
    } catch {
        Write-Warning "Failed to process: $($_.FullName) -> $targetPath"
        Write-Warning $_.Exception.Message
    }
}
