"""
Nombre: Juan Sebastián Garizao Puerto
Código: 8977555
Carrera: Ingeniería de sistemas y computación
03/02/2023
Solución tarea 1 estructuras de datos
"""
### Punto 1
def verificarDiagonales(mat):
    ans = True
    diagPrin = 0
    diagSecun = len(mat) - 1
    while diagPrin < len(mat) and ans:
        if mat[diagPrin][diagPrin] != mat[diagPrin][diagSecun]:
            ans = False
        diagPrin += 1
        diagSecun -= 1    
    return ans

### Punto 2
def esCapicua(lista):
    ans = True
    i = 0
    ultimoElemento = len(lista) - 1
    while i < len(lista)//2 and ans:
        if lista[i] != lista[ultimoElemento]:
            ans = False
        i += 1
        ultimoElemento -= 1    
    return ans

### Punto 3
# a.)
def diferenciaListas(listaA, listaB):
    i = 0
    ans = []
    while i < len(listaA):
        j = 0
        flag = True
        while j < len(listaB) and flag:
            if listaA[i] == listaB[j]:
                flag = False
                listaB.pop(j)
            j += 1
        if flag:
            ans.append(listaA[i])
        i += 1
    return ans

# b.)
def leerImprimirDif():
    cases = int(input())
    i = 0
    while i < cases:
        lista1 = input().split()
        lista1.pop(0)
        lista2 = input().split()
        lista2.pop(0)
        ans = diferenciaListas(lista1,lista2)
        ans = ", ".join(ans)
        print(ans)
        i += 1

### Punto 4
def primos(N):
    i = 2
    ans =[]
    while i < N:
        j = 2
        flag = True
        while j < i and flag:
            if i % j == 0:
                flag = False
            j += 1
        if flag:
            ans.append(i)
        i += 1
    return ans

def mostrarPrimos(N):
    lista = primos(N)
    i = 0
    ans = []
    print("Números primos entre 1 y %d:"%(N))
    while i < len(lista):
        cont = 0
        num = lista[i]
        if i == len(lista) - 1:
            print("--> %d"%(num))
        else:
            print("--> %d,"%(num))
        while num != 0:
            cont += (num % 10)
            num //= 10
        if cont in lista:
            ans.append(lista[i])
        i += 1
    print()
    print("Números entre 1 y %d con suma de dígitos con valor primo:")
    i = 0
    while i < len(ans):
        if i == len(ans) - 1:
            print("%d"%(ans[i]),end="")
        else:
            print("%d, "%(ans[i]),end="")
        i += 1

# Punto 5
def sumarValoresMatriz(mat,par):
    ans = 0
    i = 0
    while i < len(par):
        fila = par[i][0]
        col = par[i][1]
        if fila in mat:
            j, flag = 0, True
            while j < len(mat[fila]) and flag:
                if mat[fila][j][0] == col:
                    flag = False
                    ans += mat[fila][j][1]
                j += 1
        i += 1
    return ans


            

            



        
        







         
