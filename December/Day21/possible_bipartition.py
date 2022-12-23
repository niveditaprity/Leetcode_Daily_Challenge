class Solution:
    def bfs(self, dislike_pairs, node, color):
        color[node] = 1
        queue = []
        queue.append(node)

        while(len(queue) > 0):
            u = queue.pop(0)
            for i in dislike_pairs[u]:
                if(color[u] == color[i]):
                    return False
                if color[i] == -1:
                    queue.append(i)
                    color[i] = 1 - color[u]
        return True

    def possibleBipartition(self, n: int, dislikes: List[List[int]]) -> bool:
        dislike_pairs = defaultdict(list)
        for i in dislikes:
            dislike_pairs[i[0]].append(i[1])
            dislike_pairs[i[1]].append(i[0])

        color = [-1]*(n+1)
        for i in range(1, n+1):
            if color[i] == -1:
                if(self.bfs(dislike_pairs, i, color) == False): 
                    return False
        return True