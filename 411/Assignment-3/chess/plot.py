import matplotlib.pyplot as plt

# Read the streak lengths from the file (make sure to adjust the file path)
with open('streak.txt', 'r') as f:
    streak_lengths = [int(line.strip()) for line in f]

# Plotting the histogram
plt.figure(figsize=(10,6))
plt.hist(streak_lengths, bins=range(0, max(streak_lengths) + 5, 5), edgecolor='black', alpha=0.7)
plt.title("Histogram of Streak Lengths from Simulations", fontsize=14)
plt.xlabel("Streak Length", fontsize=12)
plt.ylabel("Frequency", fontsize=12)

# Save the plot as an image (PNG format)
plt.savefig("streak_histogram.png")


