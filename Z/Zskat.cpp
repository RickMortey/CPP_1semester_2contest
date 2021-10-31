//#include <iostream>
//
//using namespace std;
//
//
////////@brief finds the maximum on a portion of the array
////////
////////@note there is a check for array sizes
////////
////////@param[in] **mas - array
////////
////////@param[in] min_rows - upper boundary of the part of the array
////////
////////@param[in] max_rows - lower boundary of the part of the array
////////
////////@param[in] min_colls - left boundary of the part of the array
////////
////////@param[in] max_colls - right boundary of the part of the array
////////
////////@param[in] rows - number of array lines
////////
////////@param[in] colls - number of array columns
////////
////////@param[out] x, y - coordinates of the maximum element in the section
////////
////////@return maximum in the part of the array
//
//int max_mas(int** mas, int min_rows, int max_rows, int min_colls, int max_colls,
//    int& x, int& y, int rows, int colls)
//{
//    int max = mas[min_rows][min_colls];
//    x = min_rows;
//    y = min_colls;
//    max_rows = min(max_rows, rows);
//    max_colls = min(max_colls, colls);
//    for (int i = min_rows; i < max_rows; ++i)
//    {
//        for (int j = min_colls; j < max_colls; ++j)
//        {
//            if (mas[i][j] > max)
//            {
//                max = mas[i][j];
//                x = i;
//                y = j;
//            }
//        }
//    }
//    return max;
//}
//
//int main()
//{
//    int colls;
//    int rows;
//    cin >> rows >> colls;
//    int vis_rows;
//    int vis_colls;
//    cin >> vis_rows >> vis_colls;
//    int** mas = new int* [rows];
//    for (int i = 0; i < rows; ++i)
//    {
//        mas[i] = new int[colls];
//    }
//    for (int i = 0; i < rows; ++i)
//    {
//        for (int j = 0; j < colls; ++j)
//        {
//            cin >> mas[i][j];
//        }
//    }
//    int ans_x = 0;
//    int ans_y = 0;
//    int x = ans_x, y = ans_y;
//    int max = mas[0][0];
//
//    while (ans_x < rows && ans_y < colls)
//    {
//        int x_copy = x, y_copy = y;
//        int max1 = max_mas(mas, ans_x, ans_x + vis_rows, ans_y,
//            ans_y + vis_colls, x, y, rows, colls);
//        if (max1 > max)
//        {
//            ans_x = x;
//            ans_y = y;
//            max = max1;
//        }
//        if (x == x_copy && y == y_copy)
//        {
//            break;
//        }
//    }
//    cout << ans_x << ' ' << ans_y;
//
//    for (int i = 0; i < rows; ++i)
//    {
//        delete[] mas[i];
//    }
//    delete[] mas;
//    return 0;
//}