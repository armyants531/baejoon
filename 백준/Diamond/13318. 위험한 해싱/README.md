# [Diamond II] 위험한 해싱 - 13318 

[문제 링크](https://www.acmicpc.net/problem/13318) 

### 성능 요약

메모리: 5100 KB, 시간: 4 ms

### 분류

해 구성하기, 해싱, 수학, 정수론

### 문제 설명

<p>string matching 알고리즘에는 여러 가지가 있다. KMP 알고리즘이나 Boyer­Moore 알고리즘이 그 예시이다. 하지만 지구이는 KMP를 이해할 수 없었고, Boyer­Moore는 시간복잡도가 너무 컸다. 결국 지구이는 틀릴 확률이 있지만, 간단한 방법인 해싱을 즐겨 사용하게 되었다. 해싱은 문자열을 숫자 하나로 바꾸는 해시 함수를 하나 정의한 후, 이 값이 같은지 다른지를 통해 문자열이 같은지 판별하는 방법이다.</p>

<p>지구이는 해시 함수를 다음과 같이 정의했다.</p>

<p>길이가 n인 문자열 d[0] ~ d[n­1]와 임의의 숫자 p에 대하여 해시 함수 값은 아래와 같다. (d[i]는 해당 문자의 ASCII 코드 값이다.)</p>

<p>H(p, d) = p<sup>0</sup> * d[0] + p<sup>1</sup> * d[1] + ... + p<sup>n-1</sup> * d[n­1] (mod (10^9 + 7))</p>

<p>지구이는 Codeforces 대회에서 H(29, d)를 해시 함수로 사용하였다. 이는 H(29, d) = H(29, e)인 두 문자열 d, e가 있다면, d, e는 같은 문자열로 판별하는 것을 의미한다. 하지만 우연히 같은 룸에 도토리가 있었고, 도토리는 해시 값이 같은 두 문자열을 찾아 핵을 성공시켰다.</p>

<p>결국 지구이는 그 문제를 풀지 못했으며, 도토리에게 해싱이 너무 약했기 때문에 틀렸다는 사실을 듣게 되었다. 그 후로 지구이는 해시 함수로 H(29, d) 뿐만이 아니라, p의 값이 31, 37, 41, 43, 47, 53, 59, 61, 67인 해시 함수도 사용하기로 했다. 즉, 문자열 각각에 대하여 10개의 해시 함수를 계산한 후, 모든 해시 함수의 값이 같을 때만 두 문자열이 같다고 판별하는 것이다.</p>

<p>이제 지구이는 자신이 틀릴 리가 없다고 생각하고 있다. 해시 함수 10개의 값이 같은 문자열 2개를 만들어 KMP의 아름다움을 보여주자!</p>

<p>지구이의 코드는 <a href="https://onlinejudgeimages.s3-ap-northeast-1.amazonaws.com/problem/13318/hashing.cpp"><strong><u>여기</u></strong></a>에 있다.</p>

### 입력 

 <p>입력은 없다.</p>

### 출력 

 <p>첫 번째 줄에 문자열 A를 출력한다.</p>

<p>두 번째 줄에 문자열 B를 출력한다.</p>

<p>문자열 2개는 길이는 같되 서로 달라야 하며, 길이는 300000 이하여야 한다. 또한, 문자열은 알파벳 소문자로만 구성되어야 한다.</p>

<p>출력 예시는 답이 아님에 주의하라.</p>

