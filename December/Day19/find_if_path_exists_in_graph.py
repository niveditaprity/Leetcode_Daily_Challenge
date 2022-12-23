# using bfs
class Solution:
    def validPath(self, n: int, edges: List[List[int]], source: int, destination: int) -> bool:
        graph = defaultdict(list)
        for edge in edges:
            u = edge[0]
            v = edge[1]
            graph[u].append(v)
            graph[v].append(u)
        
        visited = [False]*n
        q = []
        q.append(source)
        visited[source] = True

        while(len(q)):
            node = q.pop(0)
            if node == destination:
                return True
            for i in graph[node]:
                if not visited[i]:
                    q.append(i)
                    visited[i] = True
        return False