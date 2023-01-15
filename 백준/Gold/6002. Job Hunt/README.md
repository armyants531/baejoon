# [Gold IV] Job Hunt - 6002 

[문제 링크](https://www.acmicpc.net/problem/6002) 

### 성능 요약

메모리: 2164 KB, 시간: 0 ms

### 분류

벨만–포드(bellman_ford), 그래프 이론(graphs)

### 문제 설명

<p>Bessie is running out of money and is searching for jobs. Farmer John knows this and wants the cows to travel around so he has imposed a rule that his cows can only make D (1 <= D <= 1,000) dollars in a city before they must work in another city. Bessie can, however, return to a city after working elsewhere for a while and again earn the D dollars maximum in that city. There is no limit on the number of times Bessie can do this.</p>

<p>Bessie's world comprises P (1 <= P <= 150) one-way paths connecting C (2 <= C <= 220) cities conveniently numbered 1..C. Bessie is currently in city S (1 <= S <= C). Path i runs one-way from city A_i to city B_i (1 <= A_i <= C; 1 <= B_i <= C) and costs nothing to traverse.</p>

<p>To help Bessie, Farmer John will give her access to his private jet service. This service features F (1 <= F <= 350) routes, each of which is a one way flight from one city J_i to a another K_i (1 <= J_i <= C; 1 <= K_i <= C) and which costs T_i (1 <= T_i <= 50,000) dollars. Bessie can pay for the tickets from future earnings if she doesn't have the cash on hand.</p>

<p>Bessie can opt to retire whenever and wherever she wants. Given an unlimited amount of time, what is the most money that Bessie can make presuming she can make the full D dollars in each city she can travel to?  Print -1 if there is no limit to this amount.</p>

### 입력 

 <ul>
	<li>Line 1: Five space-separated integers: D, P, C, F, and S</li>
	<li>Lines 2..P+1: Line i+1 contains two space-separated integers that name a one-way path from one city to another: A_i and B_i</li>
	<li>Lines P+2..P+F+1: Line P+i+1 contains three space-separated integers that name a one-way jet flight from one city to another and the price for that flight: J_i, K_i, and T_i</li>
</ul>

<p> </p>

### 출력 

 <ul>
	<li>Line 1: A single integer representing the most money she can make while following the law.</li>
</ul>

<p> </p>

