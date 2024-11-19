import networkx as nx
import matplotlib.pyplot as plt

def dijkstra(graph, start_vertex):
    # Step 1: Initialize the distances
    distances = {vertex: float('inf') for vertex in graph}
    distances[start_vertex] = 0  # The distance to the start vertex is 0
    visited = set()  # Keep track of visited nodes
    previous_nodes = {vertex: None for vertex in graph}  # To track the shortest path tree

    while len(visited) < len(graph):
        # Step 2: Find the vertex with the minimum distance that's not visited
        min_distance = float('inf')
        current_vertex = None

        for vertex in graph:
            if vertex not in visited and distances[vertex] < min_distance:
                min_distance = distances[vertex]
                current_vertex = vertex

        # Step 3: Mark the current node as visited
        visited.add(current_vertex)

        # Step 4: Update the distances to the neighbors
        for neighbor, weight in graph[current_vertex]:
            if neighbor not in visited:
                new_distance = distances[current_vertex] + weight
                if new_distance < distances[neighbor]:
                    distances[neighbor] = new_distance
                    previous_nodes[neighbor] = current_vertex  # Track the previous node

    return distances, previous_nodes

def find_path(previous_nodes, target_vertex):
    # To reconstruct the path, trace from target vertex to start vertex
    path = []
    while target_vertex is not None:
        path.insert(0, target_vertex)
        target_vertex = previous_nodes[target_vertex]
    return path

def visualize_graph(graph, start_vertex, previous_nodes, target_vertex, color):
    # Create a NetworkX graph from the adjacency list
    G = nx.Graph()
    
    for vertex, edges in graph.items():
        for neighbor, weight in edges:
            G.add_edge(vertex, neighbor, weight=weight)
    
    pos = nx.spring_layout(G)  # Layout for the graph visualization
    
    # Create a figure for each target node
    plt.figure(figsize=(8, 6))
    nx.draw(G, pos, with_labels=True, node_size=3000, node_color="skyblue", font_size=12, font_weight="bold")
    
    # Draw edge weights
    edge_labels = nx.get_edge_attributes(G, 'weight')
    nx.draw_networkx_edge_labels(G, pos, edge_labels=edge_labels, font_size=10)
    
    # Find the path to the target node
    path = find_path(previous_nodes, target_vertex)
    
    # Get the edges that form the shortest path
    edges_in_path = [(path[i], path[i+1]) for i in range(len(path) - 1)]
    
    # Draw the edges of the shortest path in the chosen color
    nx.draw_networkx_edges(G, pos, edgelist=edges_in_path, edge_color=color, width=2)

    # Title and show the plot
    plt.title(f"Shortest Path from '{start_vertex}' to '{target_vertex}'")
    plt.show()

# Example usage:

# Representing a graph as an adjacency list
graph = {
    'A': [('B', 1), ('C', 4)],
    'B': [('A', 1), ('C', 2), ('D', 5)],
    'C': [('A', 4), ('B', 2), ('D', 1)],
    'D': [('B', 5), ('C', 1)],
}

# Run Dijkstra's algorithm starting from vertex 'A'
char = input("Enter start node:")
distances, previous_nodes = dijkstra(graph, char)

# Output the shortest distances from 'A' to all other vertices
print("Shortest distances from vertex 'A':")
for vertex, distance in distances.items():
    print(f"Distance to {vertex}: {distance}")

# Visualize the shortest path to each target node in separate figures
# Color the paths to 'B' in green, 'C' in red, and 'D' in blue

# Path to 'B'
visualize_graph(graph, 'A', previous_nodes, 'B', 'green')

# Path to 'C'
visualize_graph(graph, 'A', previous_nodes, 'C', 'red')

# Path to 'D'
visualize_graph(graph, 'A', previous_nodes, 'D', 'blue')
