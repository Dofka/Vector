# Vector

1. Panaudojant nuosavą vektoriu reikia įsitikinti kad jis taip pat veikia. Tam atlikti panaudojome: konstruktorių, destruktorių, size(), capacity(), '=' operatorių, '[]' priėjimą prie elementų, push_back() funkcijas.</br>
![My_vector](my_vector_code.png)
![My_vector](my_vector_different_functions.png)

| Bandymo nr. (elem. sk.)| Nuosavas Vector(laikas sec.)| std::vector(laikas sec.)|
|:----------------------:|:--------------:|:----------:|
| 1. 10000               |0.000531s.      |0.000625s.  |
| 2. 100000              |0.005188s.      |0.005040s.  |
| 3. 1000000             |0.026717s.      |0.035840s.  |
| 4. 10000000            |0.299027s.      |0.275683s.  |
| 5. 100000000           |2.744350s.      |2.612590s.  |
