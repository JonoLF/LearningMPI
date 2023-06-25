CC = mpicc
CFLAGS =-Iinclude -O2
SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin

# List of targets
TARGETS = ex_1 \
		  ex_2 \
		  ex_3 \
		  ex_4 \
		  ex_5 \
		  ex_6 \
		  ex_7 \
		  ex_8 \
		  ex_9 \
		  ex_10 \
		  ex_11 \
		  ex_12

# Convert target name to corresponding C file
SRCS = $(addsuffix .c, $(TARGETS))

# Convert C file to object file
OBJS = $(patsubst %.c, $(OBJ_DIR)/%.o, $(SRCS))

# Convert object file to binary file
BINS = $(addprefix $(BIN_DIR)/, $(TARGETS))

# Default rule to build all targets
all: UTIL_OBJECT \
	 $(BINS)

UTIL_OBJECT: $(OBJ_DIR)/epccutil.o

$(OBJ_DIR)/epccutil.o: $(SRC_DIR)/epccutil.c
	$(CC) $(CFLAGS) -o $@ -c $<

# Rule to build each target
$(BIN_DIR)/%: $(OBJ_DIR)/%.o
	$(CC) $(CFLAGS) -o $@ $< $(OBJ_DIR)/epccutil.o

# Rule to build object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -o $@ -c $<

# Create directories if they don't exist
$(shell mkdir -p $(BIN_DIR) $(OBJ_DIR))

# Clean rule to remove generated files
clean:
	@rm -rf $(BIN_DIR) $(OBJ_DIR)
