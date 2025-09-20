function tribonacciSequence(startSequence, length)
{
    let size = startSequence.length
    if (size == length)
      return startSeqence;
    else if (size > length)
    {
      startSeqence.length = length;
      return startSeqence;
    }
    if (size != length)
    {  
      let sum = startSequence[size - 3] + startSeqence[size - 2] + startSeqence[size - 1];
      startSeqence.push(sum);
      tribonacciSequence(startSeqence, length)
    }
    return startSeqence;
}

let startSeqence = [0, 0, 1];

let length = 0

let sequence = tribonacciSequence(startSeqence, length)

console.log(sequence);