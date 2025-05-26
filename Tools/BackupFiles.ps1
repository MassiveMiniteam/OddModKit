param (
    [Parameter(Mandatory = $true)]
    [string]$Source,

    [Parameter(Mandatory = $true)]
    [string]$Destination
)

# Create the destination directory if it doesn't exist
if (!(Test-Path -Path $Destination)) {
    New-Item -ItemType Directory -Path $Destination | Out-Null
}

# Copy the directory recursively
Copy-Item -Path (Join-Path $Source '*') -Destination $Destination -Recurse -Force
