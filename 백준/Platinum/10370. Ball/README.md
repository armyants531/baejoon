# [Platinum II] Ball - 10370 

[문제 링크](https://www.acmicpc.net/problem/10370) 

### 성능 요약

메모리: 2308 KB, 시간: 152 ms

### 분류

조합론(combinatorics), 수학(math)

### 문제 설명

<p>You are given some colored marbles arranged in a circle. The marbles can have three different colors: red, white and green. The marbles changes their color in each second. The new color of a marble depends on the marble right to it. The rules of changing color is as follows:</p>

<ul>
	<li>if the color of the marble is white then in the next second its color will be the one onits right. </li>
	<li>otherwise, the marble does not change color if the color of the one of its right is white. </li>
	<li>otherwise, if the marble has the different color than the one of its right, it will become white. </li>
	<li>otherwise, the marble will have the same color with its right. In this case, if it is red then it will become green and if it is green it will become red. </li>
</ul>

<p>You are given a string S and an integer N. Determine the state of the marbles after N seconds. If we consider S as a character array and its length is L, then we have L marbles in the circle. Marble (i+1) is in the right side of marble i. For marble (L-1), marble 0 is in its right. </p>

### 입력 

 <p>Input starts with T (T ≤ 20), the number of test cases. Each of the next T line contains S (1 ≤ |S| ≤ 20,000) and N (1 ≤ N ≤ 10^18) separated by a single space.</p>

### 출력 

 <p>For each case, output “Case #X: W R G” (without quotes) in a line where X is the case number, starting from 1, followed by a single space, and W is the number of white marbles, R is the number of red marbles and G is the number of green marbles for that particular case, each separated by a single space.</p>

