A = [1,0,0,0,4,0,1]
B= [ 0,0,0,0,3,0,0]

 Dot product = A.B = A1B1+A2B2+...+AnBn 

https://leetcode.com/discuss/interview-question/124823/
https://leetcode.com/discuss/interview-question/541492/facebook-phone-dot-product-of-sparse-vectors



1. Represent every number as a pair<pos, value> in vector.
The just a merge like techniue can find dot product.

a = [(1,2),(2,3),(100,5)]
b = [(0,5),(1,1),(100,6)]

i = 0; j = 0
result = 0
while i < len(a) and j < len(b):
    if a[i][0] == b[j][0]:
        result += a[i][1] * b[j][1]
        i += 1
        j += 1
    elif a[i][0] < b[j][0]:
        i += 1
    else:
        j += 1
print(result)


O(a+b); a = total non zero point in vector A
Ofcourse it requires the points to be sorted acc to posn.


2. Represent every vector in a map with key = posn, value = value

int main() {

  // Dot product of two sparse vectors stored in hash tables
  unordered_map<int, double> asht({{0, 1.}, {7, 2.}, {8, 3.}});
  unordered_map<int, double> bsht({{7, 4.}, {8, 9.}});

  int idx_a;
  double val_a, val_b;
  double dot = 0;

  for (auto it : asht) {
    idx_a = it.first;
    val_a = it.second;
    auto itb = bsht.find(idx_a);
    if (itb != bsht.end()) {
      val_b = itb->second;
      dot += val_a * val_b;
    }
  }
  cout << dot; // 35



O(n)


If one of the vectors is smaller than the other, then this technique will be better.

Also updates will be quicker in this approach.

