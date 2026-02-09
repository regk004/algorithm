# [Gold I] Fox Observation - 16797 

[문제 링크](https://www.acmicpc.net/problem/16797) 

### 성능 요약

메모리: 124676 KB, 시간: 248 ms

### 분류

애드 혹, 자료 구조, 그리디 알고리즘, 해시를 사용한 집합과 맵, 집합과 맵

### 제출 일자

2026년 2월 9일 19:55:13

### 문제 설명

<p>Ievan Ritola is a researcher of behavioral ecology. Her group visited a forest to analyze an ecological system of some kinds of foxes.</p>

<p>The forest can be expressed as a two-dimensional plane. With her previous research, foxes in the forest are known to live at lattice points. Here, lattice points are the points whose <var>x</var> and <var>y</var> coordinates are both integers. Two or more foxes might live at the same point.</p>

<p>To observe the biology of these foxes, they decided to put a pair of sensors in the forest. The sensors can be put at lattice points. Then, they will be able to observe all foxes inside the bounding rectangle (including the boundary) where the sensors are catty-corner to each other. The sensors cannot be placed at the points that have the same <var>x</var> or <var>y</var> coordinate; in other words the rectangle must have non-zero area.</p>

<p>The more foxes can be observed, the more data can be collected; on the other hand, monitoring a large area consumes a large amount of energy. So they want to maximize the value given by <var>N' / (|<sub>x1</sub> - x<sub>2</sub>| × |y<sub>1</sub> - y<sub>2</sub>|)</var>, where <var>N'</var> is the number of foxes observed and <var>(x<sub>1</sub>, y<sub>1</sub>)</var> and <var>(x<sub>2</sub>, y<sub>2</sub>)</var> are the positions of the two sensors.</p>

<p>Let's help her observe cute foxes!</p>

### 입력 

 <p>The input is formatted as follows.</p>

<pre><var>N</var>
<var>x<sub>1</sub></var> <var>y<sub>1</sub></var> <var>w<sub>1</sub></var>
<var>x<sub>2</sub></var> <var>y<sub>2</sub></var> <var>w<sub>2</sub></var>
:
:
<var>x<sub>N</sub></var> <var>y<sub>N</sub></var> <var>w<sub>N</sub></var>
</pre>

<p>The first line contains a single integer <var>N</var> (<var>1 ≤ N ≤ 10<sup>5</sup></var>) indicating the number of the fox lairs in the forest. Each of the next <var>N</var> lines contains three integers <var>x<sub>i</sub></var>, <var>y<sub>i</sub></var> (<var>|x<sub>i</sub>|,\, |y<sub>i</sub>| ≤ 10<sup>9</sup></var>) and <var>w<sub>i</sub></var> (<var>1 ≤ w<sub>i</sub> ≤ 10<sup>4</sup></var>), which represent there are <var>w<sub>i</sub></var> foxes at the point <var>(x<sub>i</sub>, y<sub>i</sub>)</var>. It is guaranteed that all points are mutually different.</p>

### 출력 

 <p>Output the maximized value as a fraction:</p>

<pre><var>a</var> / <var>b</var>
</pre>

<p>where <var>a</var> and <var>b</var> are integers representing the numerator and the denominato respectively. There should be exactly one space before and after the slash. The fraction should be written in the simplest form, that is, <var>a</var> and <var>b</var> must not have a common integer divisor greater than one.</p>

<p>If the value becomes an integer, print a fraction with the denominator of one (e.g. <code>5 / 1</code> to represent 5). This implies zero should be printed as <code>0 / 1</code> (without quotes).</p>

