"""
Practical Exercise P22: Artificial Neural Network Backpropagation for XOR Logic Gate  [CO5/BTL6]
Subject: Artificial Intelligence & Machine Learning Lab (MCA-263)
Student: Piyush Goel | Roll No: 09311604425 | MCA 3rd Sem
Bharati Vidyapeeth's Institute of Computer Applications & Management (BVICAM)
"""

import numpy as np
 
inputs = np.array([[0, 0], [0, 1], [1, 0], [1, 1]], dtype=float)
targets = np.array([[0], [1], [1], [0]], dtype=float)  # XOR
rng = np.random.default_rng(1)
weights_hidden = rng.normal(size=(2, 2))
weights_output = rng.normal(size=(2, 1))
bias_hidden = np.zeros((1, 2))
bias_output = np.zeros((1, 1))
learning_rate = 0.5
sigmoid = lambda value: 1 / (1 + np.exp(-value))
for _ in range(10000):
    hidden = sigmoid(inputs @ weights_hidden + bias_hidden)
    output = sigmoid(hidden @ weights_output + bias_output)
    output_error = targets - output
    output_delta = output_error * output * (1 - output)
    hidden_delta = (output_delta @ weights_output.T) * hidden * (1 - hidden)
    weights_output += learning_rate * hidden.T @ output_delta
    weights_hidden += learning_rate * inputs.T @ hidden_delta
    bias_output += learning_rate * output_delta.sum(axis=0, keepdims=True)
    bias_hidden += learning_rate * hidden_delta.sum(axis=0, keepdims=True)
print("Predictions:\n", np.round(output, 3))
