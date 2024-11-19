# Function to implement Dijkstra's Algorithm without using heap
def dijkstra(graph, start_vertex, vertices):
    # Initialize distances dictionary and set all distances to infinity
    distances = {vertex: float('infinity') for vertex in vertices}
    distances[start_vertex] = 0  # Distance to the start vertex is 0
    
    # List of unvisited vertices
    unvisited_vertices = vertices[:]

    while unvisited_vertices:
        # Find the vertex with the smallest distance from the unvisited vertices
        min_vertex = None
        for vertex in unvisited_vertices:
            if min_vertex is None or distances[vertex] < distances[min_vertex]:
                min_vertex = vertex
        
        # If the minimum distance is infinity, all remaining vertices are unreachable
        if distances[min_vertex] == float('infinity'):
            break

        # Visit the current vertex
        unvisited_vertices.remove(min_vertex)

        # Update the distances for the neighbors of the current vertex
        for neighbor, weight in graph[min_vertex].items():
            if neighbor in unvisited_vertices and weight != float('inf'):  # Skip if no edge or already visited
                new_distance = distances[min_vertex] + weight
                if new_distance < distances[neighbor]:
                    distances[neighbor] = new_distance

    return distances

# Function to convert the adjacency matrix to adjacency list
def convert_matrix_to_list(matrix, vertices):
    graph = {vertex: {} for vertex in vertices}
    
    for i in range(len(matrix)):
        for j in range(len(matrix[i])):
            if matrix[i][j] != 0 and matrix[i][j] != float('inf'):
                graph[vertices[i]][vertices[j]] = matrix[i][j]
    
    return graph

# Take number of vertices as input
n = int(input("Enter the number of vertices: "))

# Take the vertices as input
vertices = []
for i in range(n):
    vertex = input(f"Enter the name of vertex {i+1}: ")
    vertices.append(vertex)

# Take the adjacency matrix as input
print("Enter the adjacency matrix (use 'inf' for infinity or no path between vertices):")
adj_matrix = []
for i in range(n):
    row = []
    for j in range(n):
        value = input(f"Enter the weight for edge {vertices[i]} -> {vertices[j]}: ")
        if value.lower() == 'inf':
            row.append(float('inf'))
        else:
            row.append(int(value))
    adj_matrix.append(row)

# Convert the adjacency matrix to an adjacency list
graph = convert_matrix_to_list(adj_matrix, vertices)

# Take the start vertex as input
start_vertex = input(f"Enter the start vertex from {vertices}: ")

# Run Dijkstra's algorithm from the start vertex
shortest_paths = dijkstra(graph, start_vertex, vertices)

# Print the shortest path from the start vertex to each other vertex
print(f"\nShortest paths from {start_vertex}:")
for vertex, distance in shortest_paths.items():
    print(f"Distance from {start_vertex} to {vertex}: {distance}")
