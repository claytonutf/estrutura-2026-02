# 📚 README — Bibliotecas da Linguagem C (C Puro)

## 🎯 Objetivo
Este documento apresenta uma visão clara e didática sobre as bibliotecas da linguagem C, diferenciando bibliotecas padrão, bibliotecas externas e como identificar código em C puro.

---

## 🧠 O que são bibliotecas em C?

Bibliotecas em C são conjuntos de funções, macros e definições que facilitam o desenvolvimento de programas.

Exemplo:
```c
#include <stdio.h>
```

---

## ✅ Biblioteca Padrão do C

A biblioteca padrão do C é definida por normas internacionais (ISO) e está disponível em qualquer compilador compatível.

### Principais bibliotecas:

### 🔹 Entrada e saída
- `stdio.h` → printf, scanf, fgets

### 🔹 Strings
- `string.h` → strlen, strcpy, strcmp

### 🔹 Matemática
- `math.h` → sqrt, pow, sin

### 🔹 Memória e utilidades
- `stdlib.h` → malloc, free, rand, exit

### 🔹 Tipos e limites
- `limits.h` → limites de inteiros
- `float.h` → limites de ponto flutuante

### 🔹 Caracteres
- `ctype.h` → isdigit, toupper

### 🔹 Tempo
- `time.h` → time, clock

### 🔹 Outros
- `stdarg.h` → argumentos variáveis
- `signal.h` → sinais
- `setjmp.h` → controle de fluxo avançado

---

## ⚠️ Bibliotecas NÃO padrão (dependentes do sistema)

Essas bibliotecas não fazem parte do padrão da linguagem C:

### Linux / Unix
- `unistd.h`
- `pthread.h`

### Windows
- `windows.h`

### Gráficas e externas
- `GL/gl.h`
- `SDL.h`

---

## 🔍 Como identificar código em C puro?

Use os seguintes critérios:

### ✔ Uso de bibliotecas padrão
```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
```

### ✔ Ausência de recursos de C++
Código C puro NÃO usa:
- classes
- templates
- cout/cin
- new/delete

### ✔ Compilação com GCC em modo C
```bash
gcc -std=c11 programa.c
```

### ✔ Estrutura simples
- uso de funções
- uso de structs
- sem orientação a objetos

---

## 🔄 Relação com C++

Muitas bibliotecas do C também são utilizadas em C++.

Exemplo:

| C        | C++       |
|----------|-----------|
| stdio.h  | cstdio    |
| stdlib.h | cstdlib   |
| string.h | cstring   |

---

## 📌 Boas práticas

- Prefira sempre bibliotecas padrão
- Evite dependências específicas do sistema
- Use `fgets` ao invés de `scanf` para strings com espaços
- Sempre verifique retorno de funções como `malloc`

---

## 🧪 Exemplo básico

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char nome[50];

    printf("Digite seu nome: ");
    fgets(nome, 50, stdin);

    printf("Olá, %s", nome);

    return 0;
}
```

---

## 🚀 Conclusão

- A biblioteca padrão do C garante portabilidade
- Bibliotecas externas devem ser usadas com cautela
- C puro é simples, eficiente e amplamente utilizado

---

## 📎 Sugestões de estudo

- Ponteiros e alocação dinâmica
- Estruturas de dados em C
- Organização em múltiplos arquivos (.h e .c)
- Diferenças entre C e C++

---

## 🏫 Contexto acadêmico

Universidade Tecnológica Federal do Paraná 
Campus Cornélio Procópio  
Curso: Tecnologia em Análise e Desenvolvimento de Sistemas
Professor: Clayton Kossoski
