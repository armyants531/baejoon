# [Platinum II] XOR 포커 - 16685 

[문제 링크](https://www.acmicpc.net/problem/16685) 

### 성능 요약

메모리: 2020 KB, 시간: 48 ms

### 분류

가우스 소거법(gaussian_elimination), 선형대수학(linear_algebra), 수학(math)

### 문제 설명

<p>진벽이와 미야는 <strong>XOR 포커</strong>라는 게임을 하고 있다. 서로 정수가 적힌 카드를 <em>N</em>장 받고, 받은 카드 중 일부를 적절히 골라 점수를 계산하여 점수가 더 높은 쪽이 이기는 게임이다.</p>

<p>점수를 계산하는 방법은 다음과 같다.</p>

<ol>
	<li>주어진 카드 중 짝수 개의 카드를 고른다. (0개는 고를 수 없다)</li>
	<li>고른 카드에 적힌 수들의 XOR 값을 점수로 한다. (여러 정수의 XOR 값의 정의는 예제 밑의 '노트'에 나와 있다.)</li>
</ol>

<p>예를 들어서, 미야가 현재 {1, 2, 3, 3, 5} 가 적힌 카드를 가지고 있다고 하자. {2, 3, 3, 5} 을 고르면 2 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mo class="mjx-n"><mjx-c class="mjx-c2295"></mjx-c></mjx-mo></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mo>⊕</mo></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$\oplus$</span></mjx-container> 3 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mo class="mjx-n"><mjx-c class="mjx-c2295"></mjx-c></mjx-mo></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mo>⊕</mo></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$\oplus$</span></mjx-container> 3 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mo class="mjx-n"><mjx-c class="mjx-c2295"></mjx-c></mjx-mo></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mo>⊕</mo></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$\oplus$</span></mjx-container> 5 = 7이 점수가 된다. 똑같이 7이 되는 {1, 3, 5} 는 홀수개이기 때문에 고를 수 없다.</p>

<p>미야는 승부욕이 강해서 진벽이를 꼭 이기고 싶다. 미야가 승부에서 이길 수 있도록 도와주자.</p>

### 입력 

 <p>첫 번째 줄에는 미야가 가진 카드의 개수 <em>N</em> 이 주어진다. (2 ≤ <em>N</em> ≤ 100,000)</p>

<p>두 번째 줄부터 <em>N</em>개의 줄에 걸쳐 미야의 <em>i </em>번째 카드에 적힌 수 <em>a<sub>i</sub></em>가 주어진다. (0 ≤ <em>a<sub>i</sub></em> ≤ 10<sup>18</sup>)</p>

### 출력 

 <p>첫 번째 줄에 미야가 주어진 카드 XOR 포커를 할 때 만들 수 있는 점수의 최댓값을 출력한다.</p>

