# Function to implement Dijkstra's Algorithm without using heap
def dijkstra(graph, start_vertex):
    # Initialize distances dictionary and set all distances to infinity
    distances = {vertex: float('inf') for vertex in graph}
    distances[start_vertex] = 0  # Distance to the start vertex is 0
    
    unvisited_vertices = list(graph)  # List of unvisited vertices

    while unvisited_vertices:
        # Find the vertex with the smallest distance
        min_vertex = None
        for vertex in unvisited_vertices:
            if min_vertex is None or distances[vertex] < distances[min_vertex]:
                min_vertex = vertex
        
        # Visit the current vertex and remove from unvisited list
        unvisited_vertices.remove(min_vertex)

        # Update the distances for the neighbors of the current vertex
        for neighbor, weight in graph[min_vertex].items():
            if neighbor in unvisited_vertices:
                new_distance = distances[min_vertex] + weight
                if new_distance < distances[neighbor]:
                    distances[neighbor] = new_distance

    return distances

# Get the number of vertices and the vertices themselves
n = int(input("Enter the number of vertices: "))
vertices = [input(f"Enter the name of vertex {i+1}: ") for i in range(n)]

# Take the adjacency matrix as input
print("Enter the adjacency matrix (use 'inf' for infinity or no path between vertices):")
matrix = []
for i in range(n):
    row = []
    for j in range(n):
        value = input(f"Enter the weight for edge {vertices[i]} -> {vertices[j]}: ")
        if value.lower() == 'inf':
            row.append(float('inf'))
        else:
            row.append(int(value))
    matrix.append(row)

# Convert the adjacency matrix to adjacency list
graph = {}
for i in range(n):
    graph[vertices[i]] = {}
    for j in range(n):
        if matrix[i][j] != float('inf') and i != j:
            graph[vertices[i]][vertices[j]] = matrix[i][j]

# Take the start vertex as input
start_vertex = input(f"Enter the start vertex from {vertices}: ")

# Run Dijkstra's algorithm and get the shortest paths
shortest_paths = dijkstra(graph, start_vertex)

# Print the shortest path from the start vertex to each other vertex
print(f"\nShortest paths from {start_vertex}:")
for vertex, distance in shortest_paths.items():
    print(f"Distance from {start_vertex} to {vertex}: {distance}")
