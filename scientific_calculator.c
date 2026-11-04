#include "raylib.h"
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>

#undef PI
#define PI 3.14159265358979323846
#define WINDOW_W 600
#define WINDOW_H 850

typedef struct {
    Rectangle rect;
    const char *label;
    Color color;
} Button;

Color background = {10, 14, 23, 255};
Color panel      = {20, 27, 39, 255};
Color buttonBg   = {29, 38, 53, 255};
Color border     = {48, 61, 80, 255};
Color textColor  = {237, 242, 252, 255};
Color muted      = {145, 158, 180, 255};
Color purple     = {88, 83, 225, 255};
Color red        = {220, 65, 79, 255};
Color orange     = {255, 119, 35, 255};

char display[128] = "0";
char expression[128] = "";

double current = 0;
double stored = 0;
double memory = 0;

char pending = '\0';

bool newInput = true;
bool errorState = false;
bool degreeMode = true;

Button buttons[45];
int buttonCount = 0;

void AddButton(int x, int y, int w, int h,
               const char *label, Color color)
{
    buttons[buttonCount++] = (Button) {
        {x, y, w, h}, label, color
    };
}

void InitializeButtons(void)
{
    buttonCount = 0;

    int left = 24;
    int top = 315;
    int gap = 9;
    int cols = 5;

    int bw = (WINDOW_W - 2 * left - (cols - 1) * gap) / cols;
    int bh = 57;

    const char *labels[8][5] = {
        {"Deg", "Rad", "MC", "MR", "DEL"},
        {"sin", "cos", "tan", "log", "ln"},
        {"sqrt", "x2", "x3", "pow", "1/x"},
        {"(", ")", "!", "pi", "e"},
        {"7", "8", "9", "/", "*"},
        {"4", "5", "6", "-", "+"},
        {"1", "2", "3", "C", "="},
        {"0", ".", "+/-", "M+", "M-"}
    };

    for (int r = 0; r < 8; r++) {
        for (int c = 0; c < 5; c++) {

            int x = left + c * (bw + gap);
            int y = top + r * (bh + gap);

            Color col = buttonBg;

            if (strcmp(labels[r][c], "Deg") == 0 && degreeMode)
                col = purple;
            else if (strcmp(labels[r][c], "Rad") == 0 && !degreeMode)
                col = purple;
            else if (strcmp(labels[r][c], "C") == 0)
                col = red;
            else if (strcmp(labels[r][c], "=") == 0)
                col = orange;

            AddButton(x, y, bw, bh, labels[r][c], col);
        }
    }
}

double ToRadians(double x)
{
    return degreeMode ? x * PI / 180.0 : x;
}

void ShowResult(double value)
{
    if (!isfinite(value)) {
        strcpy(display, "Math Error");
        errorState = true;
        newInput = true;
        return;
    }

    current = value;
    snprintf(display, sizeof(display), "%.10g", value);

    newInput = true;
    errorState = false;
}

void InputDigit(char digit)
{
    if (errorState) {
        strcpy(display, "0");
        errorState = false;
    }

    if (newInput) {
        strcpy(display, "0");
        newInput = false;
    }

    size_t len = strlen(display);

    if (len < sizeof(display) - 2) {
        if (strcmp(display, "0") == 0)
            display[0] = digit, display[1] = '\0';
        else
            display[len] = digit, display[len + 1] = '\0';
    }

    current = atof(display);
}

void InputDecimal(void)
{
    if (errorState) {
        strcpy(display, "0");
        errorState = false;
    }

    if (newInput) {
        strcpy(display, "0");
        newInput = false;
    }

    if (strchr(display, '.') == NULL) {
        size_t len = strlen(display);

        if (len < sizeof(display) - 2) {
            display[len] = '.';
            display[len + 1] = '\0';
        }
    }
}

void SetOperator(char op)
{
    if (errorState)
        return;

    current = atof(display);

    if (pending != '\0' && !newInput) {
        switch (pending) {
            case '+': stored += current; break;
            case '-': stored -= current; break;
            case '*': stored *= current; break;
            case '/':
                if (current == 0) {
                    ShowResult(NAN);
                    pending = '\0';
                    return;
                }
                stored /= current;
                break;
            case '^': stored = pow(stored, current); break;
        }
    } else {
        stored = current;
    }

    pending = op;
    newInput = true;

    snprintf(expression, sizeof(expression),
             "%.10g %c", stored, op);
}

void Calculate(void)
{
    if (pending == '\0' || errorState)
        return;

    double b = atof(display);
    double result = stored;

    switch (pending) {
        case '+': result = stored + b; break;
        case '-': result = stored - b; break;
        case '*': result = stored * b; break;

        case '/':
            if (b == 0) result = NAN;
            else result = stored / b;
            break;

        case '^': result = pow(stored, b); break;
    }

    pending = '\0';
    strcpy(expression, "");
    ShowResult(result);
}

void ApplyButton(const char *s)
{
    double x = atof(display);

    if (strcmp(s, "C") == 0) {
        strcpy(display, "0");
        strcpy(expression, "");
        current = stored = 0;
        pending = '\0';
        newInput = true;
        errorState = false;
    }

    else if (strcmp(s, "DEL") == 0) {
        if (!errorState && !newInput) {
            size_t len = strlen(display);

            if (len > 1)
                display[len - 1] = '\0';
            else
                strcpy(display, "0");

            current = atof(display);
        }
    }

    else if (strcmp(s, "Deg") == 0) {
        degreeMode = true;
        InitializeButtons();
    }

    else if (strcmp(s, "Rad") == 0) {
        degreeMode = false;
        InitializeButtons();
    }

    else if (strcmp(s, "+") == 0) SetOperator('+');
    else if (strcmp(s, "-") == 0) SetOperator('-');
    else if (strcmp(s, "*") == 0) SetOperator('*');
    else if (strcmp(s, "/") == 0) SetOperator('/');
    else if (strcmp(s, "pow") == 0) SetOperator('^');
    else if (strcmp(s, "=") == 0) Calculate();

    else if (strcmp(s, ".") == 0) InputDecimal();

    else if (strcmp(s, "+/-") == 0) ShowResult(-x);

    else if (strcmp(s, "sin") == 0) ShowResult(sin(ToRadians(x)));
    else if (strcmp(s, "cos") == 0) ShowResult(cos(ToRadians(x)));
    else if (strcmp(s, "tan") == 0) {
        double a = ToRadians(x);

        if (fabs(cos(a)) < 1e-12)
            ShowResult(NAN);
        else
            ShowResult(tan(a));
    }

    else if (strcmp(s, "log") == 0)
        ShowResult(x > 0 ? log10(x) : NAN);

    else if (strcmp(s, "ln") == 0)
        ShowResult(x > 0 ? log(x) : NAN);

    else if (strcmp(s, "sqrt") == 0)
        ShowResult(x >= 0 ? sqrt(x) : NAN);

    else if (strcmp(s, "x2") == 0) ShowResult(x * x);
    else if (strcmp(s, "x3") == 0) ShowResult(x * x * x);
    else if (strcmp(s, "1/x") == 0)
        ShowResult(x != 0 ? 1.0 / x : NAN);

    else if (strcmp(s, "pi") == 0) ShowResult(PI);
    else if (strcmp(s, "e") == 0) ShowResult(exp(1));

    else if (strcmp(s, "!") == 0) {
        if (x < 0 || x > 170 || floor(x) != x) {
            ShowResult(NAN);
        } else {
            double f = 1;

            for (int i = 2; i <= (int)x; i++)
                f *= i;

            ShowResult(f);
        }
    }

    else if (strcmp(s, "MC") == 0) memory = 0;
    else if (strcmp(s, "MR") == 0) ShowResult(memory);
    else if (strcmp(s, "M+") == 0) memory += x;
    else if (strcmp(s, "M-") == 0) memory -= x;

    else if (strcmp(s, "(") == 0 || strcmp(s, ")") == 0) {
        // Parentheses are visual placeholders in this version.
    }

    else if (strlen(s) == 1 && s[0] >= '0' && s[0] <= '9')
        InputDigit(s[0]);
}

void DrawButton(Button b)
{
    Vector2 mouse = GetMousePosition();

    bool hover = CheckCollisionPointRec(mouse, b.rect);

    Color fill = b.color;

    if (hover) {
        fill.r = (unsigned char)fmin(255, fill.r + 17);
        fill.g = (unsigned char)fmin(255, fill.g + 17);
        fill.b = (unsigned char)fmin(255, fill.b + 17);
    }

    DrawRectangleRounded(
        (Rectangle){
            b.rect.x,
            b.rect.y + 3,
            b.rect.width,
            b.rect.height
        },
        0.18f, 8, (Color){5, 8, 14, 255}
    );

    DrawRectangleRounded(b.rect, 0.18f, 8, fill);

    DrawRectangleRoundedLinesEx(
        b.rect, 0.18f, 8, 1,
        hover ? purple : border
    );

    int fontSize = 21;

    if (strlen(b.label) >= 4)
        fontSize = 16;

    int tw = MeasureText(b.label, fontSize);

    DrawText(
        b.label,
        (int)(b.rect.x + (b.rect.width - tw) / 2),
        (int)(b.rect.y + (b.rect.height - fontSize) / 2),
        fontSize,
        textColor
    );
}

int main(void)
{
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);

    InitWindow(WINDOW_W, WINDOW_H, "Scientific Calculator");
    SetTargetFPS(60);

    SetExitKey(KEY_NULL);

    InitializeButtons();

    while (!WindowShouldClose()) {

        if (IsKeyPressed(KEY_ESCAPE))
            break;

        if (IsKeyPressed(KEY_ENTER))
            Calculate();

        if (IsKeyPressed(KEY_BACKSPACE))
            ApplyButton("DEL");

        if (IsKeyPressed(KEY_C))
            ApplyButton("C");

        for (int key = KEY_ZERO; key <= KEY_NINE; key++) {
            if (IsKeyPressed(key)) {
                char digit = '0' + (key - KEY_ZERO);
                InputDigit(digit);
            }
        }

        if (IsKeyPressed(KEY_KP_0)) InputDigit('0');
        if (IsKeyPressed(KEY_KP_1)) InputDigit('1');
        if (IsKeyPressed(KEY_KP_2)) InputDigit('2');
        if (IsKeyPressed(KEY_KP_3)) InputDigit('3');
        if (IsKeyPressed(KEY_KP_4)) InputDigit('4');
        if (IsKeyPressed(KEY_KP_5)) InputDigit('5');
        if (IsKeyPressed(KEY_KP_6)) InputDigit('6');
        if (IsKeyPressed(KEY_KP_7)) InputDigit('7');
        if (IsKeyPressed(KEY_KP_8)) InputDigit('8');
        if (IsKeyPressed(KEY_KP_9)) InputDigit('9');

        if (IsKeyPressed(KEY_PERIOD)) InputDecimal();

        if (IsKeyPressed(KEY_KP_ADD) || IsKeyPressed(KEY_EQUAL))
            SetOperator('+');

        if (IsKeyPressed(KEY_KP_SUBTRACT) || IsKeyPressed(KEY_MINUS))
            SetOperator('-');

        if (IsKeyPressed(KEY_KP_MULTIPLY))
            SetOperator('*');

        if (IsKeyPressed(KEY_KP_DIVIDE))
            SetOperator('/');

        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
            Vector2 mouse = GetMousePosition();

            for (int i = 0; i < buttonCount; i++) {
                if (CheckCollisionPointRec(mouse, buttons[i].rect)) {
                    ApplyButton(buttons[i].label);
                    break;
                }
            }
        }

        BeginDrawing();

        ClearBackground(background);

        // Header
        DrawRectangleGradientV(
            0, 0, GetScreenWidth(), 80,
            (Color){23, 31, 47, 255},
            background
        );

        DrawText("SCIENTIFIC", 25, 19, 20, purple);
        DrawText("CALCULATOR", 25, 42, 16, muted);

        DrawCircle(540, 30, 5, red);
        DrawCircle(557, 30, 5, orange);
        DrawCircle(574, 30, 5, GREEN);

        // Display panel
        DrawRectangleRounded(
            (Rectangle){20, 100, 560, 190},
            0.08f, 8, panel
        );

        DrawRectangleRoundedLinesEx(
            (Rectangle){20, 100, 560, 190},
            0.08f, 8, 2, border
        );

        DrawText(
            degreeMode ? "DEG" : "RAD",
            40, 120, 16, purple
        );

        if (strlen(expression) > 0)
            DrawText(expression, 40, 150, 19, muted);

        int fontSize = 48;

        if (strlen(display) > 12)
            fontSize = 32;

        int displayWidth = MeasureText(display, fontSize);

        DrawText(
            display,
            560 - displayWidth,
            210,
            fontSize,
            errorState ? red : textColor
        );

        // Draw calculator buttons
        for (int i = 0; i < buttonCount; i++)
            DrawButton(buttons[i]);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}