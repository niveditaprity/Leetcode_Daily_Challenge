class MedianFinder {
    PriorityQueue<Integer> MaxHeap;
    PriorityQueue<Integer> MinHeap;

    public MedianFinder() {
        MaxHeap = new PriorityQueue<>(Collections.reverseOrder());
        MinHeap = new PriorityQueue<>();
    }

    public void addNum(int num) {
        MaxHeap.offer(num);
        MinHeap.offer(MaxHeap.poll());
        if (MinHeap.size() > MaxHeap.size()) {
            MaxHeap.offer(MinHeap.poll());
        }
    }

    public double findMedian() {
        if (MinHeap.size() != MaxHeap.size()) {
            return MaxHeap.peek();
        }
        return (MinHeap.peek() + MaxHeap.peek()) / 2.0;
    }
}