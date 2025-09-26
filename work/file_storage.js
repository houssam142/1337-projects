function numberOfFiles(fileSize, fileUnit, driveSizeGb)
{
    if (fileUnit == "KB")
        fileSize = driveSizeGb * 1000000 / fileSize 
    else if (fileUnit == "B")
        fileSize = driveSizeGb * 1000000000 / fileSize
    else if (fileUnit)
        fileSize = driveSizeGb * 1000 / fileSize
    return fileSize;
}

let  fileSize = 4096

let num = numberOfFiles(fileSize, "B", 1.5)

console.log(num);