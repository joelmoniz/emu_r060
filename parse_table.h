
int parse_table[][53] = 
{{1, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 183},
{184, 2, 184, 184, 184, 2, 184, 2, 184, 184, 184, 184, 184, 2, 184, 2, 184, 184, 2, 2, 2, 184, 184, 184, 184, 184, 184, 184, 2, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 2, 2, 184, 184, 184, 2, 184, 2, 2, 2, 2, 183},
{184, 4, 184, 184, 184, 3, 184, 3, 184, 184, 184, 184, 184, 3, 184, 3, 184, 184, 3, 3, 3, 184, 184, 184, 184, 184, 184, 184, 3, 183, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 3, 3, 184, 184, 183, 3, 184, 3, 3, 3, 3, 183},
{184, 183, 184, 184, 184, 5, 184, 5, 184, 184, 184, 184, 184, 5, 184, 5, 184, 184, 5, 5, 5, 184, 184, 184, 184, 184, 184, 184, 6, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 5, 5, 184, 184, 183, 5, 184, 5, 5, 5, 5, 184},
{184, 8, 7, 184, 7, 7, 184, 7, 184, 184, 184, 184, 184, 7, 184, 7, 184, 184, 7, 7, 7, 184, 184, 184, 184, 184, 184, 184, 7, 183, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 7, 7, 184, 184, 183, 7, 184, 7, 7, 7, 7, 184},
{184, 183, 10, 184, 11, 9, 184, 9, 184, 184, 184, 184, 184, 9, 184, 9, 184, 184, 9, 9, 9, 184, 184, 184, 184, 184, 184, 184, 9, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 9, 9, 184, 184, 184, 9, 184, 9, 9, 9, 9, 184},
{184, 183, 183, 184, 183, 12, 184, 12, 184, 184, 184, 184, 184, 12, 184, 12, 184, 184, 12, 12, 12, 184, 184, 184, 184, 184, 184, 184, 13, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 12, 12, 184, 184, 184, 12, 184, 12, 12, 12, 12, 184},
{184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 14, 14, 14, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184},
{184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 16, 16, 16, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184},
{184, 183, 183, 184, 183, 17, 184, 18, 184, 184, 184, 184, 184, 18, 184, 18, 184, 184, 18, 18, 18, 184, 184, 184, 184, 184, 184, 184, 183, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 18, 18, 184, 184, 183, 18, 184, 18, 18, 18, 18, 184},
{184, 183, 183, 184, 183, 183, 184, 22, 184, 184, 184, 184, 184, 21, 184, 21, 184, 184, 24, 24, 24, 184, 184, 184, 184, 184, 184, 184, 183, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 23, 23, 184, 184, 183, 19, 184, 21, 21, 21, 20, 184},
{184, 183, 183, 184, 183, 183, 25, 183, 25, 25, 184, 184, 184, 183, 25, 183, 25, 184, 183, 183, 183, 184, 184, 26, 184, 184, 184, 184, 183, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 183, 183, 184, 184, 183, 183, 184, 183, 183, 183, 183, 184},
{184, 183, 183, 184, 183, 183, 184, 183, 184, 184, 184, 184, 184, 183, 184, 183, 184, 184, 183, 183, 183, 184, 184, 184, 183, 184, 184, 184, 183, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 27, 27, 184, 184, 183, 183, 184, 183, 183, 183, 183, 184},
{184, 183, 183, 29, 183, 183, 184, 183, 28, 184, 184, 184, 184, 183, 184, 183, 184, 184, 183, 183, 183, 184, 184, 184, 183, 184, 184, 184, 183, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 183, 183, 184, 184, 183, 183, 184, 183, 183, 183, 183, 184},
{184, 183, 183, 184, 183, 183, 184, 183, 184, 184, 184, 184, 184, 183, 184, 183, 184, 184, 30, 30, 30, 184, 184, 184, 184, 184, 184, 184, 183, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 183, 183, 184, 184, 183, 183, 184, 183, 183, 183, 183, 184},
{184, 183, 183, 33, 183, 183, 31, 183, 33, 32, 184, 184, 184, 183, 184, 183, 184, 184, 183, 183, 183, 184, 184, 184, 184, 184, 184, 184, 183, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 183, 183, 184, 184, 183, 183, 184, 183, 183, 183, 183, 184},
{184, 183, 183, 35, 183, 183, 184, 183, 34, 184, 184, 184, 184, 183, 184, 183, 184, 184, 183, 183, 183, 184, 184, 184, 184, 184, 184, 184, 183, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 183, 183, 184, 184, 183, 183, 184, 183, 183, 183, 183, 184},
{184, 183, 183, 38, 183, 183, 36, 183, 38, 37, 184, 184, 184, 183, 184, 183, 184, 184, 183, 183, 183, 184, 184, 184, 184, 184, 184, 184, 183, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 183, 183, 184, 184, 183, 183, 184, 183, 183, 183, 183, 184},
{184, 183, 183, 40, 183, 183, 39, 183, 40, 184, 184, 184, 184, 183, 184, 183, 184, 184, 183, 183, 183, 184, 184, 184, 184, 184, 184, 184, 183, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 183, 183, 184, 184, 183, 183, 184, 183, 183, 183, 183, 184},
{184, 183, 184, 183, 184, 184, 184, 184, 183, 184, 184, 184, 41, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184},
{184, 184, 184, 183, 184, 184, 184, 184, 183, 184, 184, 184, 42, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184},
{184, 44, 184, 183, 184, 184, 184, 184, 43, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184},
{184, 183, 183, 184, 183, 183, 184, 183, 184, 184, 184, 184, 184, 45, 184, 183, 184, 184, 183, 183, 183, 184, 184, 184, 184, 184, 184, 184, 183, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 183, 183, 184, 184, 183, 183, 184, 183, 183, 183, 183, 184},
{184, 183, 183, 46, 183, 183, 184, 183, 184, 184, 184, 184, 184, 183, 47, 183, 184, 184, 183, 183, 183, 184, 184, 184, 184, 184, 184, 184, 183, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 183, 183, 184, 184, 183, 183, 184, 183, 183, 183, 183, 184},
{184, 183, 183, 184, 183, 183, 184, 183, 184, 184, 184, 184, 184, 183, 184, 48, 184, 184, 183, 183, 183, 184, 184, 184, 184, 184, 184, 184, 183, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 183, 183, 184, 184, 183, 183, 184, 183, 183, 183, 183, 184},
{184, 183, 183, 49, 183, 183, 184, 183, 184, 184, 184, 184, 184, 183, 50, 183, 184, 184, 183, 183, 183, 184, 184, 184, 184, 184, 184, 184, 183, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 183, 183, 184, 184, 183, 183, 184, 183, 183, 183, 183, 184},
{184, 184, 184, 184, 184, 183, 51, 184, 184, 184, 184, 184, 184, 184, 184, 184, 52, 184, 184, 184, 184, 183, 184, 183, 184, 183, 183, 183, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 183, 183, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184},
{184, 184, 184, 184, 184, 55, 184, 184, 183, 184, 184, 184, 184, 54, 184, 54, 184, 184, 53, 53, 53, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184},
{184, 184, 184, 184, 184, 56, 184, 184, 184, 184, 184, 184, 184, 56, 184, 56, 184, 57, 56, 56, 56, 184, 184, 183, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184},
{184, 184, 184, 184, 184, 59, 184, 184, 58, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 183, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184},
{184, 184, 184, 184, 184, 183, 184, 184, 183, 184, 184, 184, 184, 184, 184, 184, 184, 184, 60, 61, 62, 184, 184, 184, 183, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184},
{184, 184, 184, 184, 184, 183, 184, 184, 183, 184, 184, 184, 184, 63, 184, 64, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184},
{184, 184, 184, 184, 184, 65, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 183, 184, 183, 183, 183, 183, 183, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 183, 183, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184},
{184, 183, 183, 184, 183, 183, 66, 183, 67, 184, 184, 184, 184, 183, 68, 183, 66, 184, 183, 183, 183, 183, 184, 183, 183, 183, 183, 183, 183, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 183, 183, 184, 184, 183, 183, 184, 183, 183, 183, 183, 184},
{184, 183, 183, 184, 183, 69, 184, 183, 184, 184, 184, 184, 184, 183, 184, 183, 184, 184, 183, 183, 183, 70, 184, 183, 183, 183, 183, 183, 183, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 183, 183, 184, 184, 183, 183, 184, 183, 183, 183, 183, 184},
{184, 71, 183, 184, 183, 183, 184, 183, 72, 184, 184, 184, 184, 183, 184, 183, 184, 184, 183, 183, 183, 183, 184, 183, 183, 183, 183, 183, 183, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 183, 183, 184, 184, 183, 183, 184, 183, 183, 183, 183, 184},
{184, 183, 184, 184, 184, 73, 184, 184, 183, 184, 184, 183, 184, 184, 184, 184, 184, 184, 184, 184, 184, 74, 183, 184, 183, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 183, 183, 183, 183, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184},
{184, 183, 183, 184, 183, 183, 76, 183, 75, 184, 184, 184, 184, 183, 184, 183, 184, 184, 183, 183, 183, 183, 184, 183, 183, 183, 183, 183, 183, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 183, 183, 184, 184, 183, 183, 184, 183, 183, 183, 183, 184},
{184, 183, 183, 184, 183, 77, 184, 183, 184, 184, 184, 184, 184, 183, 184, 183, 184, 184, 183, 183, 183, 77, 184, 77, 183, 77, 77, 77, 183, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 77, 77, 184, 184, 183, 183, 184, 183, 183, 183, 183, 184},
{184, 183, 183, 79, 183, 183, 184, 183, 78, 184, 184, 184, 184, 183, 184, 183, 184, 184, 183, 183, 183, 183, 184, 183, 183, 183, 183, 183, 183, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 183, 183, 184, 184, 183, 183, 184, 183, 183, 183, 183, 184},
{184, 184, 184, 184, 184, 80, 183, 184, 183, 184, 184, 184, 184, 184, 183, 184, 183, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184},
{184, 82, 184, 82, 184, 184, 82, 184, 82, 81, 184, 184, 184, 184, 82, 184, 82, 184, 184, 184, 184, 184, 184, 184, 82, 184, 184, 184, 184, 184, 82, 82, 82, 82, 82, 82, 82, 82, 82, 82, 82, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184},
{184, 183, 184, 183, 184, 184, 183, 184, 183, 184, 184, 83, 184, 184, 183, 184, 183, 184, 184, 184, 184, 184, 84, 184, 183, 184, 184, 184, 184, 184, 183, 183, 183, 183, 183, 183, 183, 183, 183, 183, 183, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184},
{184, 85, 184, 85, 184, 184, 85, 184, 85, 86, 184, 184, 184, 184, 85, 184, 85, 184, 184, 184, 184, 184, 184, 184, 85, 184, 184, 184, 184, 184, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184},
{184, 183, 184, 184, 184, 87, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 87, 184, 184, 184, 87, 87, 87, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184},
{184, 89, 184, 184, 184, 184, 184, 184, 88, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184},
{184, 183, 184, 183, 184, 91, 184, 184, 183, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 90, 184, 184, 183, 90, 90, 90, 184, 184, 183, 183, 183, 183, 183, 183, 183, 183, 183, 183, 183, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184},
{184, 183, 184, 183, 184, 184, 184, 184, 183, 93, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 92, 183, 184, 184, 184, 184, 184, 183, 183, 183, 183, 183, 183, 183, 183, 183, 183, 183, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184},
{184, 183, 184, 183, 184, 184, 184, 184, 183, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 94, 183, 184, 184, 184, 184, 184, 183, 183, 183, 183, 183, 183, 183, 183, 183, 183, 183, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184},
{184, 183, 184, 183, 184, 95, 184, 184, 183, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 96, 184, 184, 184, 184, 184, 183, 183, 183, 183, 183, 183, 183, 183, 183, 183, 183, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184},
{184, 183, 184, 184, 184, 97, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 98, 98, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184},
{184, 183, 184, 183, 184, 184, 184, 184, 183, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 183, 99, 100, 184, 184, 184, 183, 183, 183, 183, 183, 183, 183, 183, 183, 183, 183, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184},
{184, 183, 184, 183, 184, 184, 184, 184, 183, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 101, 184, 184, 183, 103, 103, 102, 184, 184, 183, 183, 183, 183, 183, 183, 183, 183, 183, 183, 183, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184},
{184, 183, 183, 184, 183, 183, 184, 183, 184, 184, 184, 184, 184, 183, 184, 183, 184, 184, 183, 183, 183, 184, 184, 184, 184, 184, 184, 184, 104, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 183, 183, 184, 184, 184, 183, 184, 183, 183, 183, 183, 184},
{184, 106, 106, 184, 106, 106, 184, 106, 184, 184, 184, 184, 184, 106, 184, 106, 184, 184, 106, 106, 106, 184, 184, 184, 184, 184, 184, 184, 106, 105, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 106, 106, 184, 184, 184, 106, 184, 106, 106, 106, 106, 184},
{184, 183, 183, 184, 183, 183, 184, 183, 184, 184, 184, 184, 108, 183, 184, 183, 184, 184, 183, 183, 183, 184, 184, 184, 184, 184, 184, 184, 107, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 183, 183, 184, 184, 184, 183, 184, 183, 183, 183, 183, 184},
{184, 183, 184, 184, 184, 183, 184, 183, 184, 184, 184, 184, 184, 183, 184, 183, 184, 184, 183, 183, 183, 184, 184, 184, 184, 184, 184, 184, 109, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 183, 183, 184, 184, 183, 183, 184, 183, 183, 183, 183, 184},
{184, 110, 184, 184, 184, 110, 184, 110, 184, 184, 184, 184, 184, 110, 184, 110, 184, 184, 110, 110, 110, 184, 184, 184, 184, 184, 184, 184, 110, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 110, 110, 184, 184, 183, 110, 184, 110, 110, 110, 110, 184},
{184, 112, 184, 184, 184, 112, 184, 112, 184, 184, 184, 184, 184, 112, 184, 112, 184, 184, 112, 112, 112, 184, 184, 184, 184, 184, 184, 184, 112, 111, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 112, 112, 184, 184, 112, 112, 184, 112, 112, 112, 112, 184},
{184, 183, 184, 184, 184, 183, 184, 183, 184, 184, 184, 184, 114, 183, 184, 183, 184, 184, 183, 183, 183, 184, 184, 184, 184, 184, 184, 184, 113, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 183, 183, 184, 184, 183, 183, 184, 183, 183, 183, 183, 184},
{184, 184, 184, 183, 184, 115, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 115, 184, 115, 184, 115, 115, 115, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 115, 115, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184},
{184, 184, 184, 117, 184, 184, 184, 184, 116, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184},
{184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 183, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 183, 184, 183, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 118, 118, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184},
{184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 120, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 120, 184, 120, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 119, 119, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184},
{184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 183, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 183, 184, 183, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 183, 183, 184, 184, 121, 121, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184},
{184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 123, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 123, 184, 123, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 123, 123, 122, 122, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184},
{184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 183, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 183, 184, 183, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 183, 183, 183, 183, 124, 124, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184},
{184, 184, 184, 184, 184, 125, 184, 184, 184, 184, 184, 183, 184, 184, 184, 184, 184, 184, 184, 184, 184, 125, 183, 126, 183, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 183, 183, 183, 183, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184},
{184, 184, 184, 183, 184, 127, 184, 184, 183, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 127, 184, 127, 183, 127, 127, 127, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 127, 127, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184},
{184, 184, 184, 129, 184, 184, 184, 184, 129, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 129, 184, 184, 184, 184, 184, 128, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184},
{184, 184, 184, 183, 184, 130, 184, 184, 183, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 130, 184, 130, 183, 130, 130, 130, 184, 184, 183, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 130, 130, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184},
{184, 184, 184, 132, 184, 184, 184, 184, 132, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 132, 184, 184, 184, 184, 184, 132, 131, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184},
{184, 184, 184, 183, 184, 133, 184, 184, 183, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 133, 184, 133, 183, 133, 133, 133, 184, 184, 183, 183, 184, 184, 184, 184, 184, 184, 184, 184, 184, 133, 133, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184},
{184, 184, 184, 135, 184, 184, 184, 184, 135, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 135, 184, 184, 184, 184, 184, 135, 135, 134, 134, 134, 134, 134, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184},
{184, 184, 184, 184, 184, 183, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 183, 184, 183, 184, 183, 183, 183, 184, 184, 184, 184, 136, 137, 138, 139, 140, 184, 184, 184, 184, 183, 183, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184},
{184, 184, 184, 183, 184, 141, 184, 184, 183, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 141, 184, 141, 183, 141, 141, 141, 184, 184, 183, 183, 183, 183, 183, 183, 183, 184, 184, 184, 184, 141, 141, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184},
{184, 184, 184, 143, 184, 184, 184, 184, 143, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 143, 184, 184, 184, 184, 184, 143, 143, 143, 143, 143, 143, 143, 142, 142, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184},
{184, 184, 184, 184, 184, 183, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 183, 184, 183, 184, 183, 183, 183, 184, 184, 184, 184, 184, 184, 184, 184, 184, 144, 145, 184, 184, 183, 183, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184},
{184, 184, 184, 183, 184, 146, 184, 184, 183, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 146, 184, 146, 183, 146, 146, 146, 184, 184, 183, 183, 183, 183, 183, 183, 183, 183, 183, 184, 184, 146, 146, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184},
{184, 184, 184, 148, 184, 184, 184, 184, 148, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 148, 184, 184, 184, 184, 184, 148, 148, 148, 148, 148, 148, 148, 148, 148, 147, 147, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184},
{184, 184, 184, 184, 184, 183, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 183, 184, 183, 184, 183, 183, 183, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 149, 150, 183, 183, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184},
{184, 184, 184, 183, 184, 152, 184, 184, 183, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 152, 184, 152, 183, 152, 152, 152, 184, 184, 183, 183, 183, 183, 183, 183, 183, 183, 183, 183, 183, 151, 151, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184},
{184, 184, 184, 184, 184, 183, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 183, 184, 183, 184, 183, 183, 183, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 153, 154, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184},
{184, 184, 184, 183, 184, 155, 184, 184, 183, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 155, 184, 156, 183, 155, 155, 155, 184, 184, 183, 183, 183, 183, 183, 183, 183, 183, 183, 183, 183, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184},
{184, 184, 184, 183, 184, 157, 184, 184, 183, 184, 184, 184, 184, 184, 184, 184, 184, 184, 158, 158, 158, 157, 184, 157, 183, 157, 157, 157, 184, 184, 183, 183, 183, 183, 183, 183, 183, 183, 183, 183, 183, 157, 157, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184},
{184, 183, 184, 183, 184, 159, 184, 184, 183, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 183, 184, 184, 184, 184, 184, 183, 183, 183, 183, 183, 183, 183, 183, 183, 183, 183, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184},
{184, 183, 184, 183, 184, 184, 184, 184, 160, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 161, 184, 184, 184, 184, 184, 183, 183, 183, 183, 183, 183, 183, 183, 183, 183, 183, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184},
{184, 183, 183, 184, 183, 183, 184, 183, 184, 184, 184, 184, 184, 183, 184, 183, 184, 184, 183, 183, 183, 184, 184, 162, 184, 184, 184, 184, 183, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 183, 183, 184, 184, 183, 183, 184, 183, 183, 183, 183, 184},
{184, 183, 183, 184, 183, 163, 184, 183, 184, 184, 184, 184, 184, 183, 184, 183, 184, 184, 183, 183, 183, 184, 184, 184, 164, 184, 184, 184, 183, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 183, 183, 184, 184, 183, 183, 184, 183, 183, 183, 183, 184},
{184, 183, 184, 184, 184, 183, 184, 183, 184, 184, 184, 184, 184, 183, 184, 183, 184, 184, 183, 183, 183, 184, 184, 184, 184, 184, 184, 184, 183, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 183, 183, 166, 165, 184, 183, 184, 183, 183, 183, 183, 184},
{184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 183, 167, 184, 184, 184, 184, 184, 184, 184, 184},
{184, 184, 184, 184, 184, 168, 184, 168, 184, 184, 184, 184, 184, 168, 184, 168, 184, 184, 168, 168, 168, 184, 184, 184, 184, 184, 184, 184, 168, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 168, 168, 183, 183, 169, 168, 184, 168, 168, 168, 168, 184},
{184, 184, 184, 184, 184, 170, 184, 184, 184, 184, 184, 184, 183, 170, 184, 170, 184, 184, 170, 170, 170, 184, 184, 184, 171, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184},
{184, 184, 184, 184, 184, 184, 184, 184, 172, 184, 184, 184, 183, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 173, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184},
{184, 183, 183, 184, 183, 183, 184, 183, 184, 184, 184, 184, 184, 183, 184, 183, 184, 184, 183, 183, 183, 184, 184, 184, 184, 184, 184, 184, 183, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 183, 183, 184, 184, 183, 174, 184, 183, 183, 183, 183, 184},
{184, 183, 183, 184, 183, 183, 184, 183, 184, 184, 184, 184, 184, 178, 184, 179, 184, 184, 183, 183, 183, 184, 184, 184, 184, 184, 184, 184, 183, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 183, 183, 184, 184, 183, 183, 184, 175, 176, 177, 183, 184},
{184, 183, 183, 184, 183, 183, 184, 183, 184, 184, 184, 184, 184, 183, 184, 183, 184, 184, 183, 183, 183, 184, 184, 184, 184, 184, 184, 184, 183, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 183, 183, 184, 184, 183, 183, 184, 183, 183, 183, 180, 184},
{184, 184, 184, 184, 184, 181, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 183, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184, 182, 182, 184, 184, 184, 184, 184, 184, 184, 184, 184, 184},
};