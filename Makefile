CC = gcc
CCFLAGS = -Wall -std=c99 -O3
LDLIBS = -lglfw -lGL
.PHONY: init

rwildcard=$(foreach d,$(wildcard $1*),$(call rwildcard,$d/,$2) $(filter $(subst *,%,$2), $d))

SRC_DIR = $(sort $(dir $(wildcard src/*/*)))
OBJ_DIR = bin
INC_DIR = ./src/melkor

SOURCE = $(call rwildcard, src, *.c)
HEADERS = $(call rwildcard, src, *.h)
OBJECTS = ${SOURCE:%.c=$(OBJ_DIR)/%.o}
EXECUTABLE = melkor

all: init $(OBJECTS) $(EXECUTABLE)
	@ ./$(EXECUTABLE)

${EXECUTABLE}: $(OBJECTS)
	$(CC) $(LDFLAGS) -o $@ $(OBJECTS) $(LDLIBS)

$(OBJ_DIR)/%.o: %.c
	$(CC) -I$(INC_DIR) -c $< -o $@ $(CCFLAGS)

init:
	@$(foreach p, $(SOURCE), mkdir -p $(addprefix $(OBJ_DIR)/, $(dir $p));)

clean:
	rm -rf $(OBJ_DIR)
