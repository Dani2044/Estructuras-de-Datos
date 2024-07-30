# Proyecto de Manipulación de Mallas Poligonales

## Pontificia Universidad Javeriana
### Departamento de Ingeniería de Sistemas
### Curso: Estructuras de Datos, 2024-30

## Autores

- Daniel Felipe Castro Moreno
- Victoria Sepúlveda Acero
- Juan Rozo Tarache

## Descripción

Este proyecto proporciona un sistema para manipular mallas poligonales que representan objetos tridimensionales. Permite cargar, listar, y procesar estas mallas para realizar operaciones como calcular cajas envolventes, encontrar vértices cercanos y rutas más cortas.

## Funcionalidades

1. **Organización de la Información**
   - **Cargar objeto:** `cargar nombre_archivo` - Carga un objeto 3D desde un archivo.
   - **Listar objetos:** `listado` - Muestra los objetos cargados en memoria.
   - **Caja envolvente:** `envolvente nombre_objeto` - Calcula la caja envolvente de un objeto.
   - **Caja envolvente global:** `envolvente` - Calcula la caja envolvente que incluye todos los objetos en memoria.
   - **Descargar objeto:** `descargar nombre_objeto` - Elimina un objeto de la memoria.
   - **Guardar objeto:** `guardar nombre_objeto nombre_archivo` - Guarda un objeto en un archivo.

2. **Vértices Más Cercanos**
   - **Vértice cercano:** `v_cercano px py pz nombre_objeto` - Encuentra el vértice más cercano a un punto específico en un objeto.
   - **Vértice cercano global:** `v_cercano px py pz` - Encuentra el vértice más cercano a un punto específico entre todos los objetos cargados.
   - **Vértices cercanos a caja:** `v_cercanos_caja nombre_objeto` - Encuentra los vértices más cercanos a las esquinas de la caja envolvente de un objeto.

3. **Rutas Más Cortas**
   - **Ruta corta entre vértices:** `ruta_corta i1 i2 nombre_objeto` - Encuentra la ruta más corta entre dos vértices en un objeto.
   - **Ruta corta al centro:** `ruta_corta_centro i1 nombre_objeto` - Encuentra la ruta más corta entre un vértice y el centro del objeto.

## Uso

La aplicación se ejecuta en una consola Unix/Linux.
