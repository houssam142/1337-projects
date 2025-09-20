function tribonacciSequence(startSequence, length)
{
    let size = startSequence.length
    console.log(startSeqence[size - 3]);
    if (size == length)
      return startSequence;
    let num = 0
    if (size <= length)
    {
        tribonacciSequence(startSequence[size - 3] + startSeqence[size - 2] + startSeqence[size - 1], length)
        size++;
    }
    return startSeqence;
}

let startSeqence = [0, 0, 1];

let length = 20

let sequence = tribonacciSequence(startSeqence, length)

console.log(sequence);