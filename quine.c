char* prog = "#include <stdio.h>\\n#include <stdbool.h>\\n\\nvoid escape(char* s) {\\n    char* p = s;\\n    char c;\\n    while ((c = *p++)) {\\n        if (c == '\\\\\\\\') {\\n            printf(\\\"\\\\\\\\\\\\\\\\\");\\n        } else if (c == '\\\"') {\\n            printf(\\\"\\\\\\\\\\\\\"\\\");\\n        } else {\\n            putchar(c);\\n        }\\n    }\\n}\\n\\nvoid unescape(char* s) {\\n    char* p = s;\\n    char c;\\n    bool slash = false;\\n    while ((c = *p++)) {\\n        if (slash) {\\n            if (c == 'n') {\\n                putchar('\\\\n');\\n            } else if (c == '\\\"') {\\n                putchar('\\\"');\\n            } else if (c == '\\\\\\\\') {\\n                putchar('\\\\\\\\');\\n            }\\n            slash = false;\\n        } else {\\n            if (c == '\\\\\\\\') {\\n                slash = true;\\n            } else {\\n                putchar(c);\\n            }\\n        }\\n    }\\n}\\n\\nint main(void) {\\n    printf(\\\"char* prog = \\\\\\\"\\\");\\n    escape(prog);\\n    printf(\\\"\\\\\\\";\\\\n\\\\n\\\");\\n    unescape(prog);\\n}\\n";

#include <stdio.h>
#include <stdbool.h>

void escape(char* s) {
    char* p = s;
    char c;
    while ((c = *p++)) {
        if (c == '\\') {
            printf("\\\\");
        } else if (c == '"') {
            printf("\\\"");
        } else {
            putchar(c);
        }
    }
}

void unescape(char* s) {
    char* p = s;
    char c;
    bool slash = false;
    while ((c = *p++)) {
        if (slash) {
            if (c == 'n') {
                putchar('\n');
            } else if (c == '"') {
                putchar('"');
            } else if (c == '\\') {
                putchar('\\');
            }
            slash = false;
        } else {
            if (c == '\\') {
                slash = true;
            } else {
                putchar(c);
            }
        }
    }
}

int main(void) {
    printf("char* prog = \"");
    escape(prog);
    printf("\";\n\n");
    unescape(prog);
}
