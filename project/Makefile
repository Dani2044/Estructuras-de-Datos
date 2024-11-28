CC = g++                     # Usamos g++ para compilar C++
CFLAGS = -Wall -g            # Flags para compilación (incluyendo depuración)
SRC_DIR = src                 # Carpeta de código fuente
INCLUDE_DIR = include         # Carpeta de archivos de encabezado
BUILD_DIR = build             # Carpeta de archivos compilados
EXEC = build/program          # Nombre del ejecutable

# Obtener todos los archivos .cpp
SRCS = $(wildcard $(SRC_DIR)/*.cpp)
OBJS = $(SRCS:$(SRC_DIR)/%.cpp=$(BUILD_DIR)/%.o)

# Regla por defecto
all: $(EXEC)

# Regla para compilar el ejecutable
$(EXEC): $(OBJS)
	$(CC) $(OBJS) -o $(EXEC)

# Regla para compilar archivos .cpp a .o
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

# Limpiar archivos generados
clean:
	rm -rf $(BUILD_DIR) $(EXEC)

# Regla de ejecución
run: $(EXEC)
	./$(EXEC)