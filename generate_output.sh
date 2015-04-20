./a.out ./test_cases/submitted_test1.txt > ./test_cases/output1.txt
./a.out ./test_cases/submitted_test2.txt > ./test_cases/output2.txt
./a.out ./test_cases/submitted_test3.txt > ./test_cases/output3.txt
./a.out ./test_cases/submitted_test4.txt > ./test_cases/output4.txt
./a.out ./test_cases/submitted_test5.txt > ./test_cases/output5.txt
./a.out ./test_cases/misc_test1.txt > ./test_cases/output1m.txt
./a.out ./test_cases/misc_test2.txt > ./test_cases/output2m.txt
sed -n -e '/Abstract Syntax tree:/,$p' ./test_cases/output1.txt > ./test_cases/out_compare.txt
sed -n -e '/Abstract Syntax tree:/,$p' ./test_cases/output2.txt >> ./test_cases/out_compare.txt
sed -n -e '/Abstract Syntax tree:/,$p' ./test_cases/output3.txt >> ./test_cases/out_compare.txt
sed -n -e '/Abstract Syntax tree:/,$p' ./test_cases/output4.txt >> ./test_cases/out_compare.txt
sed -n -e '/Abstract Syntax tree:/,$p' ./test_cases/output5.txt >> ./test_cases/out_compare.txt
sed -n -e '/Abstract Syntax tree:/,$p' ./test_cases/output1m.txt > ./test_cases/out_compare_misc.txt
sed -n -e '/Abstract Syntax tree:/,$p' ./test_cases/output2m.txt >> ./test_cases/out_compare_misc.txt
