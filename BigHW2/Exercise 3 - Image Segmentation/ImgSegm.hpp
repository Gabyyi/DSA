#pragma once
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

const int SIZE = 6;
const int threshold=10;
const int dim = SIZE * SIZE + 2;

class ImageSegm {
private:
    
    ifstream fin;
    ofstream fout;
    int image[SIZE][SIZE], imageNew[SIZE][SIZE];
    int graph[dim][dim], residualGraph[dim][dim], cutGraph[dim][dim];
    int start = 0;
    int sink = dim - 1;

    void dfs(int s, bool visited[]) {
        visited[s] = true;
        for (int i = 0; i < dim; i++) {
            if (cutGraph[s][i] && !visited[i]) {
                dfs(i, visited);
            }
        }
    }

    int getMinWeight() {
        int minweight = 99999;
        for (int i = 1; i < dim - 1; i++) {
            for (int j = 1; j < dim - 1; j++) {
                if (minweight > residualGraph[i][j] && residualGraph[i][j] != 0) {
                    minweight = residualGraph[i][j];
                }
            }
        }
        return minweight;
    }

    int getWeight(int node1, int node2) {
        if (abs(node1 - node2) < threshold) {
            return 0;
        }
        else return (255 - abs(node1 - node2));
    }

    void readImage() {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                fin >> image[i][j];
            }
        }

        for (int i = 1; i < dim - 1; i++) {
            int row = (i - 1) / SIZE;
            int col = (i - 1) % SIZE;

            graph[start][i] = 1;
            graph[i][sink] = 1;
            residualGraph[i][start] = 255;
            residualGraph[sink][i] = 255;

            if (row > 0) {
                graph[i][i - SIZE] = 1;
                graph[i - SIZE][i] = 1;
                int nodeWeight = getWeight(image[row][col], image[row - 1][col]);
                residualGraph[i][i - SIZE] = nodeWeight;
                residualGraph[i - SIZE][i] = nodeWeight;
            }
            if (row < SIZE - 1) {
                graph[i][i + SIZE] = 1;
                graph[i + SIZE][i] = 1;
                int nodeWeight = getWeight(image[row][col], image[row + 1][col]);
                residualGraph[i][i + SIZE] = nodeWeight;
                residualGraph[i + SIZE][i] = nodeWeight;
            }
            if (col > 0) {
                graph[i][i - 1] = 1;
                graph[i - 1][i] = 1;
                int nodeWeight = getWeight(image[row][col], image[row][col - 1]);
                residualGraph[i][i - 1] = nodeWeight;
                residualGraph[i - 1][i] = nodeWeight;
            }
            if (col < SIZE - 1) {
                graph[i][i + 1] = 1;
                graph[i + 1][i] = 1;
                int nodeWeight = getWeight(image[row][col], image[row][col + 1]);
                residualGraph[i][i + 1] = nodeWeight;
                residualGraph[i + 1][i] = nodeWeight;
            }
        }
    }

    void generateCut() {
        int minweight = getMinWeight();

        for (int i = 0; i < dim; i++) {
            for (int j = 0; j < dim; j++) {
                cutGraph[i][j] = graph[i][j];
            }
        }

        for (int i = 1; i < dim - 1; i++) {
            for (int j = 1; j < dim - 1; j++) {
                if (residualGraph[i][j] > minweight) {
                    cutGraph[i][j] = 0;
                    cutGraph[j][i] = 0;
                    cutGraph[start][i] = 0;
                    cutGraph[start][j] = 0;
                    cutGraph[i][sink] = 0;
                    cutGraph[j][sink] = 0;
                }
            }
        }
    }

    void displayGraphs() {
        fout << "Image:\n";
        for(int i=0;i<SIZE;i++)
        {
            for (int j = 0; j < SIZE; j++)
                fout << std::setfill(' ') << std::setw(3) << image[i][j] << " ";
            fout << "\n";
        }
        fout << "Graph:\n";
        for (int i = 0; i < dim; i++) {
            for (int j = 0; j < dim; j++) {
                fout << std::setfill(' ') << std::setw(3) << graph[i][j] << " ";
            }
            fout << "\n";
        }

        fout << "Residual Graph:\n";
        for (int i = 0; i < dim; i++) {
            for (int j = 0; j < dim; j++) {
                fout << std::setfill(' ') << std::setw(3) << residualGraph[i][j] << " ";
            }
            fout << "\n";
        }

       
    }

    void generateNewImage() {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                imageNew[i][j] = 0;
            }
        }

        fout << "New image:\n";

        bool visited[dim];
        for (int i = 0; i < dim; i++) {
            visited[i] = 0;
        }
        dfs(0, visited);

        for (int i = 0; i < dim; i++) {
            int row = (i - 1) / SIZE;
            int col = (i - 1) % SIZE;
            if (visited[i] && (getMinWeight() + image[row][col]) <= 255) {
                imageNew[row][col] = image[row][col];
            }
        }

        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                fout << std::setfill(' ') << std::setw(3) << imageNew[i][j] << " ";
            }
            fout << "\n";
        }
    }

public:
    ImageSegm(const char* inputFileName, const char* outputFileName) : fin(inputFileName), fout(outputFileName) {}

    void process() {
        readImage();
        generateCut();
        displayGraphs();
        generateNewImage();
    }
};
