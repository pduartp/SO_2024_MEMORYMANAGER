# Variáveis
CXX = g++
CXXFLAGS = -Wall -std=c++11  # Flags de compilação
OBJ = main.o  # Objetos que serão gerados
TARGET = main  # Nome do executável

# Regras
all: $(TARGET)

# Como gerar o executável
$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o $(TARGET)

# Como gerar o arquivo .o a partir de .cpp
main.o: main.cpp SimpleMemoryManager.hpp
	$(CXX) $(CXXFLAGS) -c main.cpp

# Limpar arquivos gerados
clean:
	rm -f $(OBJ) $(TARGET)

# Regra para rodar o programa
run: $(TARGET)
	./$(TARGET)

# Regras padrão para garantir que o make saiba o que fazer
.PHONY: all clean run
