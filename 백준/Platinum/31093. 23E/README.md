# [Platinum V] 23E - 31093 

[문제 링크](https://www.acmicpc.net/problem/31093) 

### 성능 요약

메모리: 2912 KB, 시간: 56 ms

### 분류

많은 조건 분기, 그리디 알고리즘

### 제출 일자

2024년 1월 4일 01:29:28

### 문제 설명

<p>동현이는 2023년의 끝을 조금 특별하게 기념하기 위하여 7-Segment Display를 이용한 장식물을 만들기로 했다. 동현이는 $N$개의 Display가 일렬로 꼭 맞게 들어가는 틀을 준비하고, $N$개의 Display에 각각 <span style="color:#e74c3c;"><code>2</code></span>, <span style="color:#e74c3c;"><code>3</code></span>, <span style="color:#e74c3c;"><code>E</code></span> 중 하나를 표시하여 틀에 모두 끼워 넣었다.</p>

<p style="text-align: center;"><img alt="" src="https://u.acmicpc.net/29e02e6f-4d26-4aee-a288-4d0f1b1953a3/d-1.png" style="height: 204px; width: 500px;"></p>

<p>동현이는 짝수를 좋아하기 때문에 $N$은 짝수로 정하였다. 그리고, 동현이는 점대칭 역시 좋아하기 때문에 장식물을 180도 돌렸을 때 원래 모습과 비슷할수록 아름다운 장식물이라고 생각한다. 원래 장식물과 180도 돌린 장식물에서 위치와 표시된 글자가 모두 일치하는 Display의 개수를 장식물의 <strong>아름다움</strong>이라고 하자. 구체적으로는 아래와 같이 정의한다.</p>

<ul>
	<li>원래 장식물과 180도 돌린 장식물의 왼쪽에서 $i$번째 Display에 표시된 글자를 각각 $S_i$, $T_i$라고 하자. ($1\le i\le N$)</li>
	<li>$f($<span style="color:#e74c3c;"><code>2</code></span>$)=$<span style="color:#e74c3c;"><code>2</code></span>, $f($<span style="color:#e74c3c;"><code>3</code></span>$)=$<span style="color:#e74c3c;"><code>E</code></span>, $f($<span style="color:#e74c3c;"><code>E</code></span>$)=$<span style="color:#e74c3c;"><code>3</code></span> 이라고 하자.</li>
	<li>$T_i=f(S_{N+1-i})$ 이다.</li>
	<li>장식물의 아름다움은 $S_i=T_i$ 인 $i$ ($1\le i\le N$) 의 개수이다.</li>
</ul>

<p>예제 1의 입력에 해당하는 처음 장식물은 아래 그림과 같이 아름다움이 4임을 알 수 있다.</p>

<p style="text-align: center;"><img alt="" src="https://u.acmicpc.net/c3f79041-59f3-4be1-b077-4e6a2a1e2a73/d-2.png" style="height: 378px; width: 500px;"></p>

<p>장식물에서 서로 다른 두 Display의 위치를 서로 바꾸는 것을 <strong>교환</strong>이라고 하자. 동현이는 처음에 만든 장식물에서 교환을 여러 차례 반복하여 장식물을 더욱 아름답게 만들려고 하는데, 교환은 귀찮은 일이므로 최대 $K$번까지만 하려고 한다. 동현이를 위해, 각 정수 $i$($0 \le i \le K$)에 대해 처음 장식물에서 교환을 최대 $i$번 수행했을 때 얻을 수 있는 장식물의 최대 아름다움을 모두 구하자.</p>

### 입력 

 <p>첫째 줄에 동현이가 처음에 만든 장식물에 들어간 7-Segment Display의 개수 $N$, 최대 교환 횟수 $K$가 공백으로 구분되어 주어진다.</p>

<p>둘째 줄에 처음 장식물의 각 Display에 표시된 글자를 나타내는 길이 $N$의 문자열 $S$가 주어진다. $S$의 $i$번째 글자는 장식물의 왼쪽에서 $i$번째 Display에 표시된 글자이다.</p>

### 출력 

 <p>$K+1$개의 줄에 걸쳐, 이 중 $i$번째 줄에는 처음 장식물에서 교환을 최대 $i-1$번 수행했을 때 얻을 수 있는 장식물의 최대 아름다움을 출력한다.</p>

