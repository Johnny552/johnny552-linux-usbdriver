# === Toolchain ===
CC        = sdcc
PACKHEX   = packihx
PROJECT   = johnny552
FREQ_SYS  = 24000000

# === Directories ===
SRC_DIR   = src
INC_DIR   = include
BUILD_DIR = build

# === Flags ===
CFLAGS = -mmcs51 --model-small \
         --xram-size 0x0400 --xram-loc 0x0000 \
         --code-size 0x3800 \
         -I$(INC_DIR) -DFREQ_SYS=$(FREQ_SYS)

# === Source Files ===
SRC = $(wildcard $(SRC_DIR)/*.c)
OBJ = $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.rel, $(SRC))

# === Targets ===
all: $(PROJECT).hex

$(BUILD_DIR)/%.rel: $(SRC_DIR)/%.c
	@mkdir -p $(BUILD_DIR)
	$(CC) -c $(CFLAGS) $< -o $@

$(PROJECT).ihx: $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $@

$(PROJECT).hex: $(PROJECT).ihx
	$(PACKHEX) $< > $@

flash: $(PROJECT).hex
	wchisp write $<

clean:
	rm -rf $(BUILD_DIR) *.ihx *.hex *.lst *.map *.mem

.PHONY: all clean flash
