#include <iostream>
#include <cuda_runtime.h>

__global__ void sum_area_table(int* input, int* output, int width, int height) {
    int x = blockIdx.x * blockDim.x + threadIdx.x;
    int y = blockIdx.y * blockDim.y + threadIdx.y;

    if (x < width && y < height) {
        int index = y * width + x;
        int sum = input[index];

        if (x > 0) {
            sum += output[index - 1];
        }

        if (y > 0) {
            sum += output[index - width];
        }

        if (x > 0 && y > 0) {
            sum -= output[index - width - 1];
        }

        output[index] = sum;
    }
}

void generate_input(int* input, int width, int height) {
    for (int i = 0; i < width * height; i++) {
        input[i] = rand() % 10;
    }
}

void print_output(int* output, int width, int height) {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            std::cout << output[y * width + x] << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    const int width = 5;
    const int height = 5;
    const int size = width * height * sizeof(int);

    int* input, * output;
    cudaMallocManaged(&input, size);
    cudaMallocManaged(&output, size);

    generate_input(input, width, height);

    dim3 threads_per_block(16, 16);
    dim3 num_blocks((width + threads_per_block.x - 1) / threads_per_block.x, (height + threads_per_block.y - 1) / threads_per_block.y);

    sum_area_table << <num_blocks, threads_per_block >> > (input, output, width, height);

    cudaDeviceSynchronize();

    print_output(output, width, height);

    cudaFree(input);
    cudaFree(output);

    return 0;
}