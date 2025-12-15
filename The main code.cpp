// #include <SFML/Graphics.hpp>
// #include <ctime>

// using namespace sf; //включаем пространство имен sf, чтобы постоянно не писать sf::
// const int CELL_SIZE = 25;
// const int n = 9;
// const int m = 9;
// const int mines = 10;
// int to_win = m * n - mines;
// bool start = true;
// int flag = 0; // 0 - игра, -1 - проигрыш, -2 - победа
// int flags = mines;
// int star = 0;
// int tim = 0;

// // Создает игровое поле после первого клика игрока.
// void init(int**field, int x, int y){ //двумерный масив
//     //int x, int y - координаты первого клика игрока
// 	int coun = 0; //счетчик размещенных мин
// 	int seed = time(0); //текущее время
//     srand(seed); // Seed = время - каждый раз новая последовательность
//     flags = mines;
//     to_win = m*n-mines; //Игрок побеждает, когда to_win == 0
// 	while(coun < mines){
// 		int y_mina = rand()%n; // Случайная СТРОКА (от 0 до n-1)
// 		int x_mina = rand()%m; // Случайная КОЛОНКА (от 0 до m-1)
// 		// Проверка: можно ли поставить мину в (y_mina,x_mina)?
// 		if(abs(y-y_mina) + abs(x-x_mina) > 3 && field[y_mina][x_mina] != -1){
// 			field[y_mina][x_mina] = -1; //ставим мину
// 			if(y_mina != 0 && field[y_mina-1][x_mina] != -1) field[y_mina-1][x_mina]++;   // Увеличиваем счетчик у клетки СВЕРХУ от мины
// 			if(y_mina != n-1 && field[y_mina+1][x_mina] != -1) field[y_mina+1][x_mina]++; // Снизу (если не нижний край)
// 			if(x_mina != 0 && field[y_mina][x_mina-1] != -1) field[y_mina][x_mina-1]++;   // Слева (если не левый край)
// 			if(x_mina != m-1 && field[y_mina][x_mina+1] != -1) field[y_mina][x_mina+1]++; // Справа (если не правый край)

// 			if(y_mina != 0 && x_mina != 0 && field[y_mina-1][x_mina-1] != -1) field[y_mina-1][x_mina-1]++;   // Верхний левый
// 			if(y_mina != n-1 && x_mina != 0 && field[y_mina+1][x_mina-1] != -1) field[y_mina+1][x_mina-1]++; // Нижний левый
// 			if(y_mina != n-1 && x_mina != m-1 && field[y_mina+1][x_mina+1] != -1) field[y_mina+1][x_mina+1]++;
// 			if(y_mina != 0 && x_mina != m-1 && field[y_mina-1][x_mina+1] != -1) field[y_mina-1][x_mina+1]++;

            
//             coun++;
//         }
//     }
//     // Запуск таймера
//     star = time(0); // Запоминаем момент начала
//     tim = 0; // tim = time(0) - star;  // Текущее время минус время начала
// }
// // Рекурсивная функция открытия клеток:  открывает клетку и, если она пустая (0), рекурсивно открывает всех соседей.
// bool openfild(int** field, int** opened, int y_mina, int x_mina) {
//     if(y_mina >= n || y_mina < 0 || x_mina >= m || x_mina < 0) return false;  // Проверка, что координаты в пределах поля
//     // Открытие текущей клетки
//     if (opened[y_mina][x_mina] == 0) { //если ещё не открыта
//         opened[y_mina][x_mina] = 1; // Помечаем как открытую
//         to_win--;  // Уменьшаем счетчик клеток для победы
//     }
    
//     if(field[y_mina][x_mina] == 0) {  // если рядом с клеткой нет мин
//         if(y_mina != 0 && opened[y_mina-1][x_mina] == 0) openfild(field, opened, y_mina-1, x_mina);
//         if(y_mina != n-1 && opened[y_mina+1][x_mina] == 0) openfild(field, opened, y_mina+1, x_mina);
//         if(x_mina != 0 && opened[y_mina][x_mina-1] == 0) openfild(field, opened, y_mina, x_mina-1);
//         if(x_mina != m-1 && opened[y_mina][x_mina+1] == 0) openfild(field, opened, y_mina, x_mina+1);
        
//         if(y_mina != 0 && x_mina != 0 && opened[y_mina-1][x_mina-1] == 0) openfild(field, opened, y_mina-1, x_mina-1);
//         if(y_mina != n-1 && x_mina != 0 && opened[y_mina+1][x_mina-1] == 0) openfild(field, opened, y_mina+1, x_mina-1);
//         if(y_mina != n-1 && x_mina != m-1 && opened[y_mina+1][x_mina+1] == 0) openfild(field, opened, y_mina+1, x_mina+1);
//         if(y_mina != 0 && x_mina != m-1 && opened[y_mina-1][x_mina+1] == 0) openfild(field, opened, y_mina-1, x_mina+1);
//     }
//     return true;
// }

// int main() {
//     VideoMode vid;
//     vid.width = CELL_SIZE * (m + 2);
//     vid.height = CELL_SIZE * (n + 4);
//     RenderWindow window(vid, "Minesweeper 9x9", Style::Default);
    
//     Texture but;
//     but.loadFromFile("buttens (2).png");
//     Texture num;
//     num.loadFromFile("numbers (2).png");
//     Texture text;
//     text.loadFromFile("Text (3).png");
//     Texture smile;
//     smile.loadFromFile("emodjy.jpg");
//     srand(time(NULL));
    

    
//     RectangleShape cell(Vector2f(CELL_SIZE, CELL_SIZE));
//     cell.setTexture(&but);
//     cell.setTextureRect(IntRect(0, 0, 25, 25));
    
//     RectangleShape number(Vector2f(20, 35.5));
//     number.setTexture(&num);
//     number.setTextureRect(IntRect(0, 0, 20, 35.4));
    
//     RectangleShape result(Vector2f(158, 86));
//     result.setTexture(&text);
//     RectangleShape textbox2(Vector2f(235, 28));
// 	textbox2.setTexture(&text);

//     RectangleShape smiley(Vector2f(154, 150));
//     smiley.setTexture(&smile);
    
//     int** field = new int*[n];  //массив указателей на строки
//     for(int i = 0; i < n; i++) {
//         field[i] = new int[m];
//         for(int j = 0; j < m; j++) {
//             field[i][j] = 0;  // вначале инициализируем все нулями и сохраняем строку в массив (из нулей)
//         }
//     }
    
//     int** opened = new int*[n];
//     for(int i = 0; i < n; i++) {
//         opened[i] = new int[m];
//         for(int j = 0; j < m; j++) {
//             opened[i][j] = 0;
//         }
//     }
    
//     while (window.isOpen()) {  // пока открыто окно
//         Event event;  // событие, чтобы окно закрылось 
//         while (window.pollEvent(event)) {
//             if (event.type == Event::Closed) {
//                 window.close();
//             }
            
//             if (event.type == Event::MouseButtonPressed) {
//                 Vector2i pos = Mouse::getPosition(window);
//                 int x = pos.x;
//                 int y = pos.y;
                
//                 if (event.mouseButton.button == Mouse::Left) {
//                     int smileyX = (25 * (m + 2)) / 2 - 12;
//                     int smileyY = 25;
//                     // Клик на смайлик (посередине сверху) для рестарта
//                     if (x >= smileyX && x <= smileyX + 25 && 
//                         y >= smileyY && y <= smileyY + 25) {
//                         for(int i = 0; i < n; i++) {
//                             for(int j = 0; j < m; j++) {
//                                 field[i][j] = 0;
//                                 opened[i][j] = 0;
//                             }
//                         }
//                         start = true;
//                         flag = 0;
//                         flags = mines;
//                         to_win = m * n - mines;
//                         star = 0;
//                         tim = 0;
//                         continue;
//                     }
                    
            
//                     if (y < 25*(n+3) && x < 25*(m+1) && y > 75 && x > 25) {
//                         int cellY = (y - 75) / 25;
//                         int cellX = (x - 25) / 25;
                        
//                         if (opened[cellY][cellX] == 0) {
//                             if (start) { // Если это ПЕРВЫЙ клик в игре
//                                 init(field, cellY, cellX); // генерация поля
//                             }
//                             openfild(field, opened, cellY, cellX);   // Открываем клетку
//                             start = false;  //больше не первый клик
//                         }
                        
//                         if (opened[cellY][cellX] == 1 && field[cellY][cellX] == -1) {
//                             field[cellY][cellX] = -2;  // Взорвавшаяся мина
//                             flag = -1;
//                             for(int i = 0; i < n; i++) { //открываем все поле для просмотра
//                                 for(int j = 0; j < m; j++) {
//                                     if(opened[i][j] == -1 && field[i][j] >= 0) field[i][j] = -3;
//                                     opened[i][j] = 1;
//                                 }
//                             }
//                         }
//                     }
//                 }
                
//                 if (event.mouseButton.button == Mouse::Right) { //Это механика установки флажков (правый клик) для отметки предполагаемых мин.
//                     if (y < 25*(n+3) && x < 25*(m+1) && y > 75 && x > 25) {
//                         int cellY = (y - 75) / 25;
//                         int cellX = (x - 25) / 25;
                        
//                         if (opened[cellY][cellX] == 0) {
//                             opened[cellY][cellX] = -1;
//                             flags--;
//                         }
//                         else if (opened[cellY][cellX] == -1) {
//                             opened[cellY][cellX] = 0;
//                             flags++;
//                         }
//                     }
//                 }
//             }
//         }
        
//         window.clear(Color(96, 96, 96));
        
//         if(to_win == 0 && flag == 0) flag = -2;
//         int window_width = 25 * (m + 2);
//         int text_width = 158;
//         int center_x = (window_width - text_width) / 2;
//         if (flag == 1){
//             textbox2.setPosition((25*(m+2)-235)/2, (25*(n+4)-94)/2);
//             textbox2.setTextureRect(IntRect(0, 56, 235, 28));
//             window.draw(textbox2);
//             textbox2.move(0, 33);
//             textbox2.setTextureRect(IntRect(0, 84, 235, 28));
//             window.draw(textbox2);
    
            
//         }
//         else{
//         // (победа)
//         if(flag == -2) {
//             result.setPosition(center_x, 25);
//             result.setTextureRect(IntRect(0, 0, 158, 43));
//             window.draw(result);
//         }
//         // (поражение):
//         if(flag == -1) {
//             result.setPosition(center_x, 25);
//             result.setTextureRect(IntRect(0, 43, 158, 43));
//             window.draw(result);
//         }
        
//         // Счетчик флагов
//         number.setPosition(30, 25);
//         number.setTextureRect(IntRect(0, (11-flags/100)*35.5, 20, 35.5));
//         window.draw(number);
//         number.move(20, 0);
//         number.setTextureRect(IntRect(0, (11-(flags%100)/10)*35.5, 20, 35.5));
//         window.draw(number);
//         number.move(20, 0);
//         number.setTextureRect(IntRect(0, (11-(flags%10))*35.5, 20, 35.5));
//         window.draw(number);
        
//         // Таймер
//         if (star > 0 && flag == 0) tim = (time(0) - star);
//         number.setPosition(25*(m+2) - 50, 25);
//         number.setTextureRect(IntRect(0, (11-(tim%10))*35.5, 20, 35.5));
//         window.draw(number);
//         number.move(-20, 0);
//         number.setTextureRect(IntRect(0, (11-(tim%60)/10)*35.5, 20, 35.5));
//         window.draw(number);
//         number.move(-20, 0);
//         number.setTextureRect(IntRect(0, (11-(tim/60))*35.5, 20, 35.5));
//         window.draw(number);
        
//         // Смайлик 
//         if(flag == 0) {
//             smiley.setTextureRect(IntRect(154, 0, 154, 150)); // обычный (первый)
//         } else if(flag == -1) {
//             smiley.setTextureRect(IntRect(308, 0, 154, 150)); // проиграл (третий)
//         } else if(flag == -2) {
//             smiley.setTextureRect(IntRect(0, 0, 154, 150)); // выиграл (второй)
//         }
//         // Масштабируем смайлик до нужного размера (25x25)
//         smiley.setScale(25.0f/154.0f, 25.0f/150.0f); // Уменьшаем до размера клетки

//         // по центру
//         int smileyX = (25 * (m + 2) - 25) / 2; 
//         smiley.setPosition(smileyX, 25);
//         window.draw(smiley);
//         // Игровое поле
//         for(int j = 0; j < n; j++) {
//             for(int i = 0; i < m; i++) {
//                 cell.setPosition(25+25*i, 75 + 25*j);
                
//                 if(opened[j][i] == 0) {
//                     cell.setTextureRect(IntRect(0, 0, 25, 25));
//                     window.draw(cell);
//                 }
//                 if(opened[j][i] == -1) {
//                     cell.setTextureRect(IntRect(0, 25, 25, 25));
//                     window.draw(cell);
//                 }
//                 if(opened[j][i] == 1) {
//                     if(field[j][i] == -1) cell.setTextureRect(IntRect(0, 125, 25, 25));
//                     else if(field[j][i] == -2) cell.setTextureRect(IntRect(0, 75, 25, 25));
//                     else if(field[j][i] == -3) cell.setTextureRect(IntRect(0, 100, 25, 25));
//                     else cell.setTextureRect(IntRect(0, 25*(15-field[j][i]), 25, 25));
//                     window.draw(cell);
//                 }
//             }
//         }
        
//         window.display();
//     }
    
//     for (int i = 0; i < n; i++) {
//         delete[] field[i];
//         delete[] opened[i];
//     }
//     delete[] field;
//     delete[] opened;
    
//     return 0;
// }
#include <SFML/Graphics.hpp>
#include <ctime>

using namespace sf; //включаем пространство имен sf, чтобы постоянно не писать sf::
const int CELL_SIZE = 25;

int n = 9;           // 9 строк 
int m = 9;           // 9 столбцов 
int mines = 10;      
const int TEXT_WIDTH = 386;
const int TEXT_HEIGHT_PER_LINE = 72; 
int to_win = m * n - mines;
bool start = true;
int flag = 1; // 1 - меню выбора, 0 - игра, -1 - проигрыш, -2 - победа
int flags = mines;
int star = 0;
int tim = 0;

// Создает игровое поле после первого клика игрока.
void init(int**field, int x, int y, int current_m, int current_n, int current_mines){ //двумерный масив
    //int x, int y - координаты первого клика игрока
	int coun = 0; 
	int seed = time(0); 
    srand(seed); // Seed = время - каждый раз новая последовательность
    flags = current_mines;
    to_win = current_m*current_n-current_mines; //Игрок побеждает, когда to_win == 0
	while(coun < current_mines){
		int y_mina = rand()%current_n; 
		int x_mina = rand()%current_m; 
		// Проверка: можно ли поставить мину в (y_mina,x_mina)?
		if(abs(y-y_mina) + abs(x-x_mina) > 3 && field[y_mina][x_mina] != -1){
			field[y_mina][x_mina] = -1; //ставим мину
		
			if(y_mina != 0 && field[y_mina-1][x_mina] != -1) field[y_mina-1][x_mina]++;   // Сверху
			if(y_mina != current_n-1 && field[y_mina+1][x_mina] != -1) field[y_mina+1][x_mina]++; // Снизу
			if(x_mina != 0 && field[y_mina][x_mina-1] != -1) field[y_mina][x_mina-1]++;   // Слева
			if(x_mina != current_m-1 && field[y_mina][x_mina+1] != -1) field[y_mina][x_mina+1]++; // Справа

			if(y_mina != 0 && x_mina != 0 && field[y_mina-1][x_mina-1] != -1) field[y_mina-1][x_mina-1]++;   // Верхний левый
			if(y_mina != current_n-1 && x_mina != 0 && field[y_mina+1][x_mina-1] != -1) field[y_mina+1][x_mina-1]++; // Нижний левый
			if(y_mina != current_n-1 && x_mina != current_m-1 && field[y_mina+1][x_mina+1] != -1) field[y_mina+1][x_mina+1]++;
			if(y_mina != 0 && x_mina != current_m-1 && field[y_mina-1][x_mina+1] != -1) field[y_mina-1][x_mina+1]++;

            coun++;
        }
    }
    // Запуск таймера
    star = time(0); 
    tim = 0; // tim = time(0) - star;  // Текущее время минус время начала
}

// Рекурсивная функция открытия клеток
bool openfild(int** field, int** opened, int y_mina, int x_mina, int current_m, int current_n) {
    if(y_mina >= current_n || y_mina < 0 || x_mina >= current_m || x_mina < 0) return false;
    
    if (opened[y_mina][x_mina] == 0) { //если ещё не открыта
        opened[y_mina][x_mina] = 1; 
        to_win--;  
    }
    
    if(field[y_mina][x_mina] == 0) {  // если рядом с клеткой нет мин
        if(y_mina != 0 && opened[y_mina-1][x_mina] == 0) openfild(field, opened, y_mina-1, x_mina, current_m, current_n);
        if(y_mina != current_n-1 && opened[y_mina+1][x_mina] == 0) openfild(field, opened, y_mina+1, x_mina, current_m, current_n);
        if(x_mina != 0 && opened[y_mina][x_mina-1] == 0) openfild(field, opened, y_mina, x_mina-1, current_m, current_n);
        if(x_mina != current_m-1 && opened[y_mina][x_mina+1] == 0) openfild(field, opened, y_mina, x_mina+1, current_m, current_n);
        
        if(y_mina != 0 && x_mina != 0 && opened[y_mina-1][x_mina-1] == 0) openfild(field, opened, y_mina-1, x_mina-1, current_m, current_n);
        if(y_mina != current_n-1 && x_mina != 0 && opened[y_mina+1][x_mina-1] == 0) openfild(field, opened, y_mina+1, x_mina-1, current_m, current_n);
        if(y_mina != current_n-1 && x_mina != current_m-1 && opened[y_mina+1][x_mina+1] == 0) openfild(field, opened, y_mina+1, x_mina+1, current_m, current_n);
        if(y_mina != 0 && x_mina != current_m-1 && opened[y_mina-1][x_mina+1] == 0) openfild(field, opened, y_mina-1, x_mina+1, current_m, current_n);
    }
    return true;
}

int main() {
    RenderWindow window(VideoMode(400, 250), "Выбор уровня сложности", Style::Default);
    Texture text;
    text.loadFromFile("Text (3).png");
    Texture but;
    but.loadFromFile("buttens (2).png");
    Texture num;
    num.loadFromFile("numbers (2).png");
    Texture smile;
    smile.loadFromFile("emodjy.jpg");
    srand(time(NULL));
    
    RectangleShape menu_1(Vector2f(TEXT_WIDTH, TEXT_HEIGHT_PER_LINE));
    menu_1.setTexture(&text);
    
    RectangleShape menu_2(Vector2f(TEXT_WIDTH, TEXT_HEIGHT_PER_LINE));
    menu_2.setTexture(&text);
    
    // Флаг для отслеживания выбора уровня
    bool level = false;
    
    // Меню выбора уровня
    while (window.isOpen() && !level) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
                return 0;
            }
            
            if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left) {
                Vector2i pos = Mouse::getPosition(window);
                int x = pos.x;
                int y = pos.y;
                
                // Проверяем клик по первой строке меню 
                if (x >= 7 && x <= 393 && y >= 50 && y <= 122) {
                    n = 9; m = 9; mines = 10;
                    level = true;
                }
                
                // Проверяем клик по второй строке меню 
                if (x >= 7 && x <= 393 && y >= 122 && y <= 194) {
                    n = 14; m = 14; mines = 35;
                    level = true;
                }
            }
        }
        
        window.clear(Color(192, 192, 192));
        menu_1.setPosition(7, 50); 
        menu_1.setTextureRect(IntRect(0, 144, TEXT_WIDTH, TEXT_HEIGHT_PER_LINE)); 
        window.draw(menu_1);
        menu_2.setPosition(7, 122); 
        menu_2.setTextureRect(IntRect(0, 216, TEXT_WIDTH, TEXT_HEIGHT_PER_LINE)); 
        window.draw(menu_2);
        window.display();
    }
    
    // Закрываем меню-окно и создаем игровое окно
    window.close();
    
    // Обновляем переменные после выбора уровня
    to_win = m * n - mines;
    flags = mines;
        // теперь создаем игровое окно с выб. размерами
    VideoMode vid;
    vid.width = CELL_SIZE * (m + 2);
    vid.height = CELL_SIZE * (n + 4);
    RenderWindow gameWindow(vid, "Minesweeper", Style::Default);
    
    // Создаем игровые объекты после выбора уровня
    RectangleShape cell(Vector2f(CELL_SIZE, CELL_SIZE));
    cell.setTexture(&but);
    cell.setTextureRect(IntRect(0, 0, 25, 25));
    
    RectangleShape number(Vector2f(20, 35.5));
    number.setTexture(&num);
    number.setTextureRect(IntRect(0, 0, 20, 35.4));
    
    RectangleShape result(Vector2f(TEXT_WIDTH, TEXT_HEIGHT_PER_LINE));
    result.setTexture(&text);
    
    RectangleShape smiley(Vector2f(154, 150));
    smiley.setTexture(&smile);
    
    // Создаем игровые массивы с выб. размерами
    int** field = new int*[n];
    for(int i = 0; i < n; i++) {
        field[i] = new int[m];
        for(int j = 0; j < m; j++) {
            field[i][j] = 0;
        }
    }
    
    int** opened = new int*[n];
    for(int i = 0; i < n; i++) {
        opened[i] = new int[m];
        for(int j = 0; j < m; j++) {
            opened[i][j] = 0;
        }
    }
    
    // Основной игровой цикл
    while (gameWindow.isOpen()) {
        Event event;
        while (gameWindow.pollEvent(event)) {
            if (event.type == Event::Closed) {
                gameWindow.close();
            }
            
            if (event.type == Event::MouseButtonPressed) {
                Vector2i pos = Mouse::getPosition(gameWindow);
                int x = pos.x;
                int y = pos.y;
                
                if (event.mouseButton.button == Mouse::Left) {
                    // Клик на смайлик для рестарта
                    int smileyX = (25 * (m + 2)) / 2 - 12;
                    int smileyY = 25;
                    
                    if (x >= smileyX && x <= smileyX + 25 && 
                        y >= smileyY && y <= smileyY + 25) {
                        // Рестарт игры
                        for(int i = 0; i < n; i++) {
                            for(int j = 0; j < m; j++) {
                                field[i][j] = 0;
                                opened[i][j] = 0;
                            }
                        }
                        start = true;
                        flag = 0;
                        flags = mines;
                        to_win = m * n - mines;
                        star = 0;
                        tim = 0;
                        continue;
                    }
                    
                    // Клик по игровому полю
                    if (y < 25*(n+3) && x < 25*(m+1) && y > 75 && x > 25) {
                        int cellY = (y - 75) / 25;
                        int cellX = (x - 25) / 25;
                        
                        if (opened[cellY][cellX] == 0) {
                            if (start) { // Первый клик
                                init(field, cellY, cellX, m, n, mines);
                            }
                            openfild(field, opened, cellY, cellX, m, n);
                            start = false;
                        }
                        
                        if (opened[cellY][cellX] == 1 && field[cellY][cellX] == -1) {
                            field[cellY][cellX] = -2;
                            flag = -1;
                            for(int i = 0; i < n; i++) {
                                for(int j = 0; j < m; j++) {
                                    if(opened[i][j] == -1 && field[i][j] >= 0) field[i][j] = -3;
                                    opened[i][j] = 1;
                                }
                            }
                        }
                    }
                }
                
                if (event.mouseButton.button == Mouse::Right) {
                    if (y < 25*(n+3) && x < 25*(m+1) && y > 75 && x > 25) {
                        int cellY = (y - 75) / 25;
                        int cellX = (x - 25) / 25;
                        
                        if (opened[cellY][cellX] == 0) {
                            opened[cellY][cellX] = -1;
                            flags--;
                        }
                        else if (opened[cellY][cellX] == -1) {
                            opened[cellY][cellX] = 0;
                            flags++;
                        }
                    }
                }
            }
        }
        
        gameWindow.clear(Color(96, 96, 96));
        
        // Проверка победы
        if(to_win == 0 && flag == 0) flag = -2;
        
        // Отрисовка результатов (победа/поражение)
        int window_width = 25 * (m + 2);
        int text_width = TEXT_WIDTH;
        int center_x = (window_width - text_width) / 2;
        
        if(flag == -2) { // Победа 
            result.setPosition(center_x, 25);
            result.setTextureRect(IntRect(0, 0, TEXT_WIDTH, TEXT_HEIGHT_PER_LINE)); // "Выигрыш"
            gameWindow.draw(result);
        }
        
        if(flag == -1) { // Поражение 
            result.setPosition(center_x, 25);
            result.setTextureRect(IntRect(0, 72, TEXT_WIDTH, TEXT_HEIGHT_PER_LINE)); // "Проигрыш"
            gameWindow.draw(result);
        }
        
        // Счетчик флагов
        number.setPosition(30, 25);
        number.setTextureRect(IntRect(0, (11-flags/100)*35.5, 20, 35.5));
        gameWindow.draw(number);
        number.move(20, 0);
        number.setTextureRect(IntRect(0, (11-(flags%100)/10)*35.5, 20, 35.5));
        gameWindow.draw(number);
        number.move(20, 0);
        number.setTextureRect(IntRect(0, (11-(flags%10))*35.5, 20, 35.5));
        gameWindow.draw(number);
        
        // Таймер
        if (star > 0 && flag == 0) tim = (time(0) - star);
        number.setPosition(25*(m+2) - 50, 25);
        number.setTextureRect(IntRect(0, (11-(tim%10))*35.5, 20, 35.5));
        gameWindow.draw(number);
        number.move(-20, 0);
        number.setTextureRect(IntRect(0, (11-(tim%60)/10)*35.5, 20, 35.5));
        gameWindow.draw(number);
        number.move(-20, 0);
        number.setTextureRect(IntRect(0, (11-(tim/60))*35.5, 20, 35.5));
        gameWindow.draw(number);
        
        // Смайлик
        if(flag == 0) {
            smiley.setTextureRect(IntRect(154, 0, 154, 150)); // обычный
        } else if(flag == -1) {
            smiley.setTextureRect(IntRect(308, 0, 154, 150)); // проиграл
        } else if(flag == -2) {
            smiley.setTextureRect(IntRect(0, 0, 154, 150)); // выиграл
        }
        
        smiley.setScale(25.0f/154.0f, 25.0f/150.0f);
        int smileyX = (25 * (m + 2) - 25) / 2; 
        smiley.setPosition(smileyX, 25);
        gameWindow.draw(smiley);
        
        // Игровое поле
        for(int j = 0; j < n; j++) {
            for(int i = 0; i < m; i++) {
                cell.setPosition(25+25*i, 75 + 25*j);
                
                if(opened[j][i] == 0) {
                    cell.setTextureRect(IntRect(0, 0, 25, 25));
                    gameWindow.draw(cell);
                }
                if(opened[j][i] == -1) {
                    cell.setTextureRect(IntRect(0, 25, 25, 25));
                    gameWindow.draw(cell);
                }
                if(opened[j][i] == 1) {
                    if(field[j][i] == -1) cell.setTextureRect(IntRect(0, 125, 25, 25));
                    else if(field[j][i] == -2) cell.setTextureRect(IntRect(0, 75, 25, 25));
                    else if(field[j][i] == -3) cell.setTextureRect(IntRect(0, 100, 25, 25));
                    else cell.setTextureRect(IntRect(0, 25*(15-field[j][i]), 25, 25));
                    gameWindow.draw(cell);
                }
            }
        }
        
        gameWindow.display();
    }
    
    // Освобождение памяти
    for (int i = 0; i < n; i++) {
        delete[] field[i];
        delete[] opened[i];
    }
    delete[] field;
    delete[] opened;
    
    return 0;
}