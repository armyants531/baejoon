# [Silver I] Product Delivery - 30860 

[문제 링크](https://www.acmicpc.net/problem/30860) 

### 성능 요약

메모리: 17652 KB, 시간: 256 ms

### 분류

그리디 알고리즘

### 제출 일자

2023년 12월 19일 01:53:16

### 문제 설명

<p>There is only one railway line connecting $(n + 1)$ cities developed along the coastline. When cities along the coast are sequentially identified by numbers between $0$ and $n$, city $(i - 1)$ and city $i$ ($1 ≤ i ≤ n$) are connected by rail, but other cities are not connected by rail.</p>

<p>Since every city except city $0$ is famous as a tourist destination, every city $i$ ($1 ≤ i ≤ n$) excluding city $0$ is preparing a variety of goods to welcome travelers ahead of the tourist season. Worldwide famous goods BFB is the most popular item in every city. However, the supplier of this product is located in city $0$.</p>

<p>There is only one store that sells BFB in each city $i$ ($1 ≤ i ≤ n$). Let $S_i$ be the BFB specialty store in city $i$. In each $S_i$, the number of BFBs expected to be sold in the tourist season is analyzed and reported to the supplier in the form of $[l_i, m_i]$. Here, $l_i$ and $m_i$ represent the minimum and the maximum number of expected required products, respectively.</p>

<p>The BFB supply company in city $0$ collects request information from stores in every city and supplies products according to the rules described below.</p>

<ul>
	<li>Select a city, say city $k$ ($1 ≤ k ≤ n$). Then, take a train departing from city $0$, travel to city $k$, and supply BFBs only to the stores along the route. In other words, the BFB supplier supplies products to $S_1, S_2, \dots , S_k$.</li>
	<li>Let $c_i$ be the number of BFBs supplied to $S_i$ ($1 ≤ i ≤ k$) while moving along the route, the condition $c_i ≤ c_{i+1}$ ($1 ≤ i ≤ k - 1$) must be satisfied.</li>
</ul>

<p>If the supplier supplies products according to the supply rules described above, it may be impossible for every store to supply the desired number of items with a single supply procedure. Therefore, the supplier must go through several supply procedures to deliver the products but must comply with the supply rules described above each time. After completing all supply procedures, each $S_i$ will have at least $l_i$ and at most $m_i$ items.</p>

<p>For example, suppose $n = 4$ and the number of items required by each store $S_i$ ($1 ≤ i ≤ 4$) are $[13,15]$, $[5,8]$, $[6,14]$, and $[3,7]$, respectively. In order for each store to supply the desired quantity of goods, there must be at least two delivery procedures. In the first delivery procedure, $6$ items can be supplied to each of the $4$ stores. Once delivery is completed in this first procedure, all stores' requests except $S_1$ are satisfied. Since $6$ items have already been delivered to $S_1$, $r$ ($7 ≤ r ≤ 9$) additional products will be delivered to $S_1$ in the second delivery procedure. Of course, there may be other delivery methods. However, at least two delivery procedures are required.</p>

<p>Write a program to calculate the minimum number of supply procedures in order to supply the number of BFBs required by each store according to the above rules.</p>

### 입력 

 <p>Your program is to read from standard input. The input starts with a line containing an integer $n$ ($1 ≤ n ≤ 10^6$), where $n$ is the number of cities in which the BFB specialty stores locate. In the following $n$ lines, the $i$-th line contains two integers $l_i$ and $m_i$ ($1 ≤ l_i ≤ m_i ≤ 10^9$) which indicate the minimum and the maximum number of expected required products by $S_i$.</p>

### 출력 

 <p>Your program is to write to standard output. Print exactly one line. The line should contain the minimum number of supply processes in order to supply the number of products required by each store according to the delivery rules.</p>

