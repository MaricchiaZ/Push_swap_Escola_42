# Estudo do Push Swap da Escola 42

## Diretrizes para a tarefa
Um conjunto de dados devem ser classificados do menor para o maior.
Você tem à sua disposição um conjunto de valores inteiros, 2 pilhas, e um conjunto de instruções para manipular as duas pilhas.
Devemos escrever um programa em C chamado push_swap que calcula e exibe
na saída padrão o menor programa, feito de instruções de linguagem Push swap,
que classifica os números inteiros recebidos como argumentos.

Os algoritmos de classificação e sua complexidade são parte essencial do sucesso nessa tarefa. É provavelmente um bom momento para olhar para estes conceitos, já que você
têm que enfrentá-los em algum momento.

Os objetivos de aprendizado deste projeto são rigor, uso de C e uso de algoritmos básicos, especialmente concentrando-se em sua complexidade.

## As regras do jogo
*O objetivo é colocar em ordem crescente os números, na pilha a*
 Você tem 2 pilhas, chamadas a e b.
- No início:
    ◦ A *pilha a* contém uma quantidade aleatória de números negativos e/ou positivos
que não pode ser duplicada.
    ◦ A *pilha b* está vazia.
Você pode realizar APENAS os seguintes movimentos:
    *sa* (swap a): Trocar os 2 primeiros elementos no topo do stack a. (Não faça nada se houver apenas um ou nenhum elemento).
    *sb* (swap b): Troque os 2 primeiros elementos no topo da pilha b.
    Não fazer nada se houver apenas um ou nenhum elemento.
    ss : sa e sb ao mesmo tempo.
    pa (empurrar a): Pegue o primeiro elemento no topo da pilha b e coloque-o no topo da pilha a.
    Não faça nada se b estiver vazio.
    pb (empurrar b): Pegue o primeiro elemento no topo de a e coloque-o no topo de b.
    Não faça nada se a estiver vazia.
    ra (girar a): Desloque todos os elementos da pilha a para cima por 1.
    O primeiro elemento se torna o último.
    rb (girar b): Deslocar para cima todos os elementos da pilha b por 1.
    O primeiro elemento passa a ser o último.
    rr : ra e rb ao mesmo tempo.
    rra (girar ao contrário a): Deslocar todos os elementos da pilha a por 1.
    O último elemento se torna o primeiro.
    rrb (giro inverso b): Deslocar para baixo todos os elementos da pilha b por 1.
    O último elemento passa a ser o primeiro.
    rrr : rra e rrb ao mesmo tempo.