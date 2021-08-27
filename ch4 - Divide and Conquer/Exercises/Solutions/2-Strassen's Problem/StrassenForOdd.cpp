#include <iostream>
#include <vector>

using namespace std;

void PrintMatrix(vector<vector<int>> Matrix, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << Matrix[i][j] << "  ";
        }
        cout << endl;
    }
}

vector<vector<int>> AddTwoMatrices(vector<vector<int>> MatrixA, vector<vector<int>> MatrixB, int n)
{
    vector<vector<int>> MatrixC;
    vector<int> row;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            row.push_back(MatrixA[i][j] + MatrixB[i][j]);
        }
        MatrixC.push_back(row);
        row = {};
    }
    return MatrixC;
}

vector<vector<int>> SubtractTwoMatrices(vector<vector<int>> MatrixA, vector<vector<int>> MatrixB, int n)
{
    vector<vector<int>> MatrixC;
    vector<int> row;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            row.push_back(MatrixA[i][j] - MatrixB[i][j]);
        }
        MatrixC.push_back(row);
        row = {};
    }
    return MatrixC;
}

vector<vector<int>> oddToEvenMatrix(vector<vector<int>> Matrix, int MatrixSize)
{
    vector<int> row(MatrixSize + 1, 0);

    for (int i = 0; i < MatrixSize; i++)
    {
        Matrix[i].push_back(0);
    }
    Matrix.push_back(row);
    return Matrix;
}

vector<vector<int>> StrassenAlgorithm(vector<vector<int>> MatrixA, vector<vector<int>> MatrixB, int MatrixSize)
{
    vector<int> Row(MatrixSize, 0);
    vector<vector<int>> MatrixC(MatrixSize, Row);

    if (MatrixSize == 1)
    {
        vector<int> row;
        MatrixC[0][0] = MatrixA[0][0] * MatrixB[0][0];
        return MatrixC;
    }
    else
    {
        int newSize = MatrixSize / 2;
        vector<int> innerVector(newSize, 0);

        // Intialize Matrices
        vector<vector<int>> MatrixA11(newSize, innerVector),
            MatrixA12(newSize, innerVector),
            MatrixA21(newSize, innerVector),
            MatrixA22(newSize, innerVector),
            MatrixB11(newSize, innerVector),
            MatrixB12(newSize, innerVector),
            MatrixB21(newSize, innerVector),
            MatrixB22(newSize, innerVector),
            MatrixC11(newSize, innerVector),
            MatrixC12(newSize, innerVector),
            MatrixC21(newSize, innerVector),
            MatrixC22(newSize, innerVector),
            s1(newSize, innerVector),
            s2(newSize, innerVector),
            s3(newSize, innerVector),
            s4(newSize, innerVector),
            s5(newSize, innerVector),
            s6(newSize, innerVector),
            s7(newSize, innerVector),
            s8(newSize, innerVector),
            s9(newSize, innerVector),
            s10(newSize, innerVector),
            p1(newSize, innerVector),
            p2(newSize, innerVector),
            p3(newSize, innerVector),
            p4(newSize, innerVector),
            p5(newSize, innerVector),
            p6(newSize, innerVector),
            p7(newSize, innerVector),
            tempMatrixA(newSize, innerVector),
            tempMatrixB(newSize, innerVector);

        for (int i = 0; i < newSize; i++)
        {
            for (int j = 0; j < newSize; j++)
            {
                MatrixA11[i][j] = MatrixA[i][j];
                MatrixA12[i][j] = MatrixA[i][j + newSize];
                MatrixA21[i][j] = MatrixA[i + newSize][j];
                MatrixA22[i][j] = MatrixA[i + newSize][j + newSize];

                MatrixB11[i][j] = MatrixB[i][j];
                MatrixB12[i][j] = MatrixB[i][j + newSize];
                MatrixB21[i][j] = MatrixB[i + newSize][j];
                MatrixB22[i][j] = MatrixB[i + newSize][j + newSize];
            }
        }

        // s1 = b12 - b22
        s1 = SubtractTwoMatrices(MatrixB12, MatrixB22, newSize);

        // s2 = a11 + a12
        s2 = AddTwoMatrices(MatrixA11, MatrixA12, newSize);

        // s3 = a21 + a22
        s3 = AddTwoMatrices(MatrixA21, MatrixA22, newSize);

        // s4 = b21 - b11
        s4 = SubtractTwoMatrices(MatrixB21, MatrixB11, newSize);

        // s5 = a11 + a22
        s5 = AddTwoMatrices(MatrixA11, MatrixA22, newSize);

        // s6 = b11 + b22
        s6 = AddTwoMatrices(MatrixB11, MatrixB22, newSize);

        // s7 = a12 - a22
        s7 = SubtractTwoMatrices(MatrixA12, MatrixA22, newSize);

        // s8 = b21 + b22
        s8 = AddTwoMatrices(MatrixB21, MatrixB22, newSize);

        // s9 = a11 - a21
        s9 = SubtractTwoMatrices(MatrixA11, MatrixA21, newSize);

        // s10 = b11 + b12
        s10 = AddTwoMatrices(MatrixB11, MatrixB12, newSize);

        // p1 = a11 * s1
        p1 = StrassenAlgorithm(MatrixA11, s1, newSize);

        // p2 = s2 * b22
        p2 = StrassenAlgorithm(s2, MatrixB22, newSize);

        // p3 = s3 * b11
        p3 = StrassenAlgorithm(s3, MatrixB11, newSize);

        // p4 = a22 * s4
        p4 = StrassenAlgorithm(MatrixA22, s4, newSize);

        // p5 = s5 * s6
        p5 = StrassenAlgorithm(s5, s6, newSize);

        // p6 = s7 * s8
        p6 = StrassenAlgorithm(s7, s8, newSize);

        // p7 = s9 * s10
        p7 = StrassenAlgorithm(s9, s10, newSize);

        // c11 = p5 + p4 - p2 + p6
        tempMatrixA = AddTwoMatrices(p5, p4, newSize);             // p5 + p4
        tempMatrixB = AddTwoMatrices(tempMatrixA, p6, newSize);    // (p5 + p4) + p6
        MatrixC11 = SubtractTwoMatrices(tempMatrixB, p2, newSize); // (p5 + p4 + p6) - p2

        // c12 = p1 + p2
        MatrixC12 = AddTwoMatrices(p1, p2, newSize);

        // c21 = p3 + p4
        MatrixC21 = AddTwoMatrices(p3, p4, newSize);

        // c22 = p5 + p1 - p3 + p7
        tempMatrixA = AddTwoMatrices(p5, p1, newSize);               // p5 + p1
        tempMatrixB = SubtractTwoMatrices(tempMatrixA, p3, newSize); // (p5 + p1) - p3
        MatrixC22 = SubtractTwoMatrices(tempMatrixB, p7, newSize);   // (p5 + p1 - p3) - p7

        // group into matrixC
        for (int i = 0; i < newSize; i++)
        {
            vector<int> row2;
            for (int j = 0; j < newSize; j++)
            {
                MatrixC[i][j] = MatrixC11[i][j];
                MatrixC[i][j + newSize] = MatrixC12[i][j];
                MatrixC[i + newSize][j] = MatrixC21[i][j];
                MatrixC[i + newSize][j + newSize] = MatrixC22[i][j];
            }
        }
    }
    return MatrixC;
}

vector<vector<int>> MatrixSizeFilter(vector<vector<int>> MatrixA, vector<vector<int>> MatrixB, int MatrixSize)
{
    vector<vector<int>> MatrixC;
    if (MatrixSize % 2 == 0)
    {
        MatrixC = StrassenAlgorithm(MatrixA, MatrixB, MatrixSize);
    }
    else if (MatrixSize %2 != 0)
    {
        MatrixA = oddToEvenMatrix(MatrixA, MatrixSize);
        MatrixB = oddToEvenMatrix(MatrixB, MatrixSize);

        cout << " " <<endl;
        MatrixC = StrassenAlgorithm(MatrixA, MatrixB, MatrixSize + 1);
        // Remove Zeros From Matrix
    }
    return MatrixC;
}

int main()
{
    vector<vector<int>> A{{1, 2, 3},
                          {4, 5, 6},
                          {7, 8, 9}};

    vector<vector<int>> B{{1, 2, 1},
                          {2, 4, 6},
                          {7, 2, 5}};

    // vector<vector<int>> A
    // {
    //     {1, 5, 0, 1, 2, 3, 7},
    //     {2, 6, 4, 5, 4, 2, 1},
    //     {3, 7, 3, 6, 4, 1, 0},
    //     {4, 8, 2, 5, 4, 2, 7},
    //     {5, 9, 4, 4, 3, 2, 1},
    //     {4, 5, 5, 2, 3, 0, 1},
    //     {1, 3, 3, 6, 5, 4, 1}
    // };

    // vector<vector<int>> B
    // {
    //     {1, 2, 3, 4, 5, 6, 7},
    //     {2, 7, 1, 2, 4, 0, 0},
    //     {3, 2, 1, 6, 0, 2, 4},
    //     {3, 5, 4, 2, 3, 0, 1},
    //     {4, 3, 3, 5, 7, 8, 7},
    //     {0, 2, 2, 3, 4, 5, 4},
    //     {6, 5, 4, 1, 0, 2, 4}
    // };

    vector<vector<int>> C;

    C = MatrixSizeFilter(A, B, 3);
    PrintMatrix(C, 3);

    // C = MatrixSizeFilter(A, B, 7);
    // PrintMatrix(C, 7);
}
