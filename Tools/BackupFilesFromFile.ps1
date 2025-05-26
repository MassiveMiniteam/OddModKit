param (
    [Parameter(Mandatory = $true)]
    [string]$InputFilePath
)

# Base paths
$projectRoot = Resolve-Path "$PSScriptRoot/.."
$contentRoot = Join-Path $projectRoot "Content"
$backupRoot = Join-Path $projectRoot "Saved/Backup"

# Read each line
Get-Content $InputFilePath | ForEach-Object {
    $gamePath = $_.Trim()
    if ($gamePath -eq "") { return }

    # Convert /Game/... to relative path from Content/
    $relativePath = $gamePath -replace "^/Game/", ""

    # Remove top-level folder (e.g. LOC/)
    $pathParts = $relativePath -split "/"
    if ($pathParts.Count -lt 2) {
        Write-Warning "Skipping invalid path: $relativePath"
        return
    }

    $strippedPath = ($pathParts[1..($pathParts.Count - 1)] -join "/")
    $relativeDir = Split-Path $strippedPath -Parent
    $assetName = Split-Path $strippedPath -Leaf

    # Paths
    $originalFolder = Join-Path $contentRoot (Split-Path $relativePath -Parent)
    $sourceFile = Join-Path $originalFolder "$assetName.uasset"
    $targetFolder = Join-Path $backupRoot $relativeDir
    $targetFile = Join-Path $targetFolder "$assetName.uasset"

    # Ensure target directory exists
    New-Item -ItemType Directory -Force -Path $targetFolder | Out-Null

    # Copy and delete
    if (Test-Path $sourceFile) {
        Copy-Item $sourceFile -Destination $targetFile -Force
        Remove-Item $sourceFile -Force
        Write-Host "Moved: $sourceFile -> $targetFile"
    } else {
        Write-Warning "File not found: $sourceFile"
    }
}
