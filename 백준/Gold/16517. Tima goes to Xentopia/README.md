# [Gold I] Tima goes to Xentopia - 16517 

[문제 링크](https://www.acmicpc.net/problem/16517) 

### 성능 요약

메모리: 9240 KB, 시간: 136 ms

### 분류

데이크스트라, 그래프 이론, 최단 경로

### 제출 일자

2026년 2월 17일 17:19:27

### 문제 설명

<p>The city of Xentopia has a well-connected railway network. The city has N junctions numbered from 1 to N. There are M pairs of railway tracks that exist between the junctions. Trains can travel in both directions on each track. Each railway track is labelled either red, blue, or white in colour.</p>

<p>Tima, a tourist in the city, wants to travel from junction S to junction T in the minimum possible time. She has a map of the railway network that she can use to achieve this goal.</p>

<p>Tima, being rather eccentric, has an interesting constraint for her travel: She wants to travel via exactly k1 red tracks, exactly k2 blue tracks, and any number of white tracks, in any order. She is fine with using a railway track more than once.</p>

<p>Can you tell the minimum time Tima will take to go from S to T, ensuring that her constraint is not violated?</p>

### 입력 

 <p>The first line contains four space-separated integers: N, (1 ≤ N ≤ 450); M, (1 ≤ M ≤ 1 100); k<sub>1</sub>; and k<sub>2</sub>, (0 ≤ k<sub>1</sub>, k<sub>2</sub> ≤ 800, k<sub>1</sub> · k<sub>2</sub> ≤ 800). Following are M lines. Each line contains four space-separated integers: U V X C, denoting that a track exists between junction U and junction V , (1 ≤ U, V ≤ N, U ≠ V ); the train covers this track in X seconds, (0 ≤ X ≤ 10<sup>9</sup>); and the track is labelled colour C, (0 ≤ C ≤ 2). A white track is denoted by C = 0, a red track is denoted by C = 1, and a blue track is denoted by C = 2.</p>

<p>The last line contains two space-separated integers S, (1 ≤ S ≤ N), and T, (1 ≤ T ≤ N), the source and destination of Tima’s journey, respectively. Note: S may be equal to T.</p>

### 출력 

 <p>Print a single integer denoting the total time Tima would take. If it is not possible for Tima to reach her destination using exactly k<sub>1</sub> red tracks, k<sub>2</sub> blue tracks, and any number of white tracks, output -1.</p>

