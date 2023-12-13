#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ROWS  
#define COLS  



void relu_activation(double *input, int size) {
    for (int i = 0; i < size; i++) {
        input[i] = fmax(0, input[i]);
    }
}

void sigmoid_activation(double *input, int size) {
    for (int i = 0; i < size; i++) {
        input[i] = 1 / (1 + exp(-input[i]));
    }
}

void dense_layer(double *input, double *weights, double *output, int input_size, int output_size) {
    for (int i = 0; i < output_size; i++) {
        output[i] = 0;
        for (int j = 0; j < input_size; j++) {
            output[i] += input[j] * weights[j + i * input_size];
        }
    }
}

int main() {
    
    normalize_data(x_train1, ROWS, COLS);

    // Define neural network parameters
    int input_size = COLS;
    int hidden_size = 128;
    int output_size = 1;

    // Allocate memory for weights
    double weights_input_hidden[input_size * hidden_size];
    double weights_hidden_output[hidden_size * output_size];

    // Allocate memory for activations
    double hidden_layer[hidden_size];
    double output_layer[output_size];

  
    dense_layer(x_train1[0], weights_input_hidden, hidden_layer, input_size, hidden_size);
    relu_activation(hidden_layer, hidden_size);

    dense_layer(hidden_layer, weights_hidden_output, output_layer, hidden_size, output_size);
    sigmoid_activation(output_layer, output_size);

    // Print the final output
    printf("Model Output: %f\n", output_layer[0]);

    return 0;
}
