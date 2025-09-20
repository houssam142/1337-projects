function numberOfPhotos(photoSizeMb, hardDriveSizeGb)
{
    hardDriveSizeGb *= 1000
    photoSizeMb = hardDriveSizeGb / photoSizeMb
    return Math.floor(photoSizeMb);
}

let photoSizeMb = 3.5

let hardDriveSizeGb = 750

let num = numberOfPhotos(photoSizeMb, hardDriveSizeGb)

console.log(num)