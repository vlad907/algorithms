import matplotlib.pyplot as plt
import networkx as nx

# Create a directed graph
G = nx.DiGraph()

# Add edges with capacities
edges = [
    ('s', 'A', 5), ('s', 'B', 2), ('s', 'C', 10),
    ('A', 'D', 2), ('B', 'A', 18), ('B', 'D', 4), ('C', 'B', 3), # Corrected edge 'C' to 'B'
    ('C', 'E', 8), ('D', 't', 4), ('E', 't', 12), ('D', 'E', 10), ('A', 'B', 1)
]

# Add edges with capacities as labels
for u, v, capacity in edges:
    G.add_edge(u, v, capacity=capacity)

# Define positions for the nodes
pos = {
    's': (0, 0), 'A': (1, 1), 'B': (1, -1), 'C': (1, -2),
    'D': (2, 0), 'E': (2, -2), 't': (3, 0)
}

# Draw the nodes
nx.draw_networkx_nodes(G, pos, node_size=500, node_color='lightblue')

# Draw the edges
nx.draw_networkx_edges(G, pos, edgelist=G.edges(), arrowstyle='->', arrowsize=20)

# Draw the labels for the nodes
nx.draw_networkx_labels(G, pos, font_size=12, font_family='sans-serif')

# Draw the edge labels with capacities
edge_labels = {(u, v): f'{G[u][v]["capacity"]}' for u, v in G.edges()}
nx.draw_networkx_edge_labels(G, pos, edge_labels=edge_labels)

# Highlight the cut (S, T) in the network by coloring specific edges
cut_edges = [('A', 'D'), ('C', 'E'), ('B', 'D')]
nx.draw_networkx_edges(G, pos, edgelist=cut_edges, edge_color='red', width=2.5, style='dashed')

# Set plot title
plt.title("Flow Network with Capacities and Cut Edges")

# Save the plot as an image
plt.savefig("flow_network_cut.png")  # Save it as an image file

# Display the plot
