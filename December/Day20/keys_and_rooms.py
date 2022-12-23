# using DFS
class Solution:
    def visit(self, graph, key, visited):
        visited[key] = True

        for room in graph[key]:
            if visited[room] == False:
                self.visit(graph, room, visited)
        return False

        
    def canVisitAllRooms(self, rooms: List[List[int]]) -> bool:
        visited = [False]*len(rooms)
        graph = dict()
        for i, v in enumerate(rooms):
            graph[i] = v
        visited[0] = True
        key = 0
        self.visit(graph, key, visited)
        return all(visited) == True