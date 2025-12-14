// #include <SFML/Graphics.hpp>
// #include <ctime>

// using namespace sf; //включаем пространство имен sf, чтобы постоянно не писать sf::
// const int CELL_SIZE = 25;
// const int n = 9;           // 9 строк
// const int m = 9;           // 9 столбцов
// const int mines = 10;
// int to_win = m*n-mines;
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

// 			coun++;
// 		}
// 	}
// 	// Запуск таймера
// 	star = time(0); // Запоминаем момент начала
// 	tim = 0; // tim = time(0) - star;  // Текущее время минус время начала





// }
// // Рекурсивная функция открытия клеток:  открывает клетку и, если она пустая (0), рекурсивно открывает всех соседей.
// bool openfild(int**field, int** opened, int y_mina, int x_mina){
// 	if(y_mina >= n || y_mina < 0 || x_mina >= m || x_mina < 0) return 0; // Проверяет, что координаты в пределах поля
//     // Открытие текущей клетки
//     if (opened[y_mina][x_mina] == 0){ //если ещё не открыта
//         opened[y_mina][x_mina] = 1;   // Помечаем как открытую
//         to_win -= 1;          // Уменьшаем счетчик клеток для победы
//     }
// 	if(field[y_mina][x_mina] == 0){  // если рядом с клеткой нет мин
// 		if(y_mina != 0 && opened[y_mina-1][x_mina] == 0) openfild(field, opened, y_mina-1, x_mina);
// 		if(y_mina != n-1 && opened[y_mina+1][x_mina] == 0) openfild(field, opened, y_mina+1, x_mina);
// 		if(x_mina != 0 && opened[y_mina][x_mina-1] == 0) openfild(field, opened, y_mina, x_mina-1);
// 		if(x_mina != m-1 && opened[y_mina][x_mina+1] == 0) openfild(field, opened, y_mina, x_mina+1);

// 		if(y_mina != 0 && x_mina != 0 && opened[y_mina-1][x_mina-1] == 0) openfild(field, opened, y_mina-1, x_mina-1);
// 		if(y_mina != n-1 && x_mina != 0 && opened[y_mina+1][x_mina-1] == 0) openfild(field, opened, y_mina+1, x_mina-1);
// 		if(y_mina != n-1 && x_mina != m-1 && opened[y_mina+1][x_mina+1] == 0) openfild(field, opened, y_mina+1, x_mina+1);
// 		if(y_mina != 0 && x_mina != m-1 && opened[y_mina-1][x_mina+1] == 0) openfild(field, opened, y_mina-1, x_mina+1);

// 	}
// 	return 1;
// }

// int main()
// {
//     // Инициализация графических компонентов
//     VideoMode vid;
// 	vid.width = CELL_SIZE *(m+2);
// 	vid.height = CELL_SIZE *(n+4);
//     RenderWindow window(vid, "Minesweeper 9x9", Style::Default);

// 	Texture but;
// 	but.loadFromFile("buttens (2).png");
// 	Texture num;
// 	num.loadFromFile("numbers (2).png");
// 	Texture text;
// 	text.loadFromFile("Text (2).png");
//     Texture smile;
// 	smile.loadFromFile("smail.png");

//     srand(time(NULL));
	
// 	RectangleShape cell(Vector2f(CELL_SIZE , CELL_SIZE ));
// 	cell.setTexture(&but);
// 	cell.setTextureRect(IntRect(0, 0, 25, 25));

// 	RectangleShape number(Vector2f(20, 35.5));
// 	number.setTexture(&num);
// 	number.setTextureRect(IntRect(0, 0, 20, 35.4));

// 	RectangleShape textbox(Vector2f(158, 86));
// 	textbox.setTexture(&text);

    
//     int** field = new int*[n]; //массив указателей на строки
//     for(int i = 0; i < n; i++){
//         int* rad = new int[m];
//         for(int j = 0; j < m; j++){
//             rad[j] = 0;  // вначале инициализируем все нулями
//         }
//         field[i] = rad;  // Сохраняем строку в массив
//     }

//     int** opened = new int*[n];
//     for(int i = 0; i < n; i++){
//         int* radb = new int[m];
//         for(int j = 0; j < m; j++){
//             radb[j] = 0;
//         }
//         opened[i] = radb;
//     }

//     while (window.isOpen()) // пока открыто окно
//     {
//         Event event; // событие, чтобы окно закрылось
//         while (window.pollEvent(event))
//         {
//             if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) //обработка левого клика мыши
//         {
//             Vector2i pos = sf::Mouse::getPosition(window);
//             int x = pos.x; //столбец
//             int y = pos.y; //строка
            
//                 if (y < 25*(n+3) && x < 25*(m+1) && y > 75 && x > 25)
//                 {
//                     if (opened[(y-75)/25][(x-25)/25] == 0){
//                         if(start){  // Если это ПЕРВЫЙ клик в игре
//                             init(field, (y -75)/25, (x-25)/25); // генерация поля
//                         }
//                         openfild(field, opened, (y -75)/25, (x-25)/25); // Открываем клетку
//                         start = false; //больше не первый клик
//                     }
//                     if (opened[(y -75)/25][(x-25)/25] == 1 && field[(y- 75)/25][(x-25)/25] == -1){ //Обработка клика на открытой мине
//                         field[(y- 75)/25][(x-25)/25] = -2; // Взорвавшаяся мина
//                         flag = -1; // проигрыш
//                         for(int i = 0; i < n; i++){ //открываем все поле для просмотра
//                             for(int j = 0; j < m; j++){
//                                 if(opened[i][j] == -1 && field[i][j] >= 0) field[i][j] = -3;
//                                 opened[i][j] = 1;
//                             }
//                         }

//                     }
//                 }
//                 // Клик на смайлик (посередине сверху) для рестарта
//                 // int smileyX = (CELL_SIZE * (m + 2) / 2) - 8;
//                 // int smileyY = 8;
//                 // if (x >= smileyX && x < smileyX + 25 &&
//                 //     y >= smileyY && y < smileyY + 25) {
//                 //     // Рестарт игры
//                 //     for(int j = 0; j < n; j++){
//                 //         for(int i = 0; i < m; i++){
//                 //             field[j][i] = 0;
//                 //             opened[j][i] = 0;
//                 //         }
//                 //     }
//                 //     vid.width = 25*(m+2);
//                 //     vid.height = 25*(n+4);
//                 //     window.create(vid, "Minesweeper 9x9", Style::Default);
//                 //     while(sf::Mouse::isButtonPressed(sf::Mouse::Left)) flag = 0;
//                 //     start = true;
//                 //     flag = 0;
//                 //     flags_left = mines;
//                 //     to_win = n * m - mines;
//                 //     star = 0;
//                 //     tim = 0;
//                 // }
//             }
                
//             if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) //Это механика установки флажков (правый клик) для отметки предполагаемых мин.
//             {
//                 Vector2i pos = sf::Mouse::getPosition(window);
//                 int x = pos.x;
//                 int y = pos.y;
//                 if (y < 25*(n+3) && x < 25*(m+1) && y > 75 && x > 25){
//                     if (opened[(y - 75)/25][(x-25) / 25] == 0){
//                         opened[(y - 75)/25][(x-25) / 25] = -1;
//                         flags--;
//                     }
//                     else if (opened[(y - 75)/25][(x-25) / 25] == -1){
//                         opened[(y - 75)/25][(x-25) / 25] = 0;
//                         flags++;
//                     }
//                 }
//             }
//             if (event.type == Event::Closed) window.close(); //Если пользователь нажал на крестик окна
//         }
//     window.clear(Color(96, 96, 96));
//     if(to_win == 0 && flag == 0) flag = -2; //-2 - это выигрышь
//     if(flag == -2){
//     // (победа)
//     textbox.setPosition(158, 86);
//     textbox.setTextureRect(IntRect(0, 0, 158, 43));  // верхняя строка
//     window.draw(textbox);
//     }

//     // (поражение):
//     if(flag == -1){
//         textbox.setPosition(158, 86);
//         textbox.setTextureRect(IntRect(0, 43, 158, 43));  // нижняя строка
//         window.draw(textbox);
//     }
//     number.setPosition(30, 25);
//     number.setTextureRect(IntRect(0, (11-flags/100)*35.5, 20, 35.5));
//     window.draw(number);
//     number.move(20, 0);
//     number.setTextureRect(IntRect(0, (11-(flags%100)/10)*35.5, 20, 35.5));
//     window.draw(number);
//     number.move(20, 0);
//     number.setTextureRect(IntRect(0, (11-(flags%10))*35.5, 20, 35.5));
//     window.draw(number);
//     if (star > 0 && flag == 0) tim = (time(0) - star);
//     number.setPosition(25*(m+2) - 50, 25);
//     number.setTextureRect(IntRect(0, (11-(tim%10))*35.5, 20, 35.5));
//     window.draw(number);
//     number.move(-20, 0);
//     number.setTextureRect(IntRect(0, (11-(tim%60)/10)*35.5, 20, 35.5));
//     window.draw(number);
//     number.move(-20, 0);
//     number.setTextureRect(IntRect(0, (11-(tim/60))*35.5, 20, 35.5));
//     window.draw(number);
//     for(int j = 0; j < n; j++){
//     for(int i = 0; i < m; i++){
//         if(opened[j][i] == 0){
//             cell.setPosition(25+25*i, 75 + 25*j);
//             cell.setTextureRect(IntRect(0, 0, 25, 25));
//             window.draw(cell);
//         }
//         if(opened[j][i] == -1){
//             cell.setPosition(25+25*i, 75 + 25*j);
//             cell.setTextureRect(IntRect(0, 25, 25, 25));
//             window.draw(cell);
//         }
//         if(opened[j][i] == 1){
//             cell.setPosition(25+25*i, 75 + 25*j);
//             if(field[j][i] == -1) cell.setTextureRect(IntRect(0, 125, 25, 25));
//             else if(field[j][i] == -2) cell.setTextureRect(IntRect(0, 75, 25, 25));
//             else if(field[j][i] == -3) cell.setTextureRect(IntRect(0, 100, 25, 25));
//             else cell.setTextureRect(IntRect(0, 25*(15-field[j][i]), 25, 25));
//             window.draw(cell);
//         }
//     }
//     }
//     }
//         window.display();
//         // === ОСВОБОЖДЕНИЕ ПАМЯТИ ПЕРЕД ВЫХОДОМ ===
//     for (int i = 0; i < n; i++) {
//         delete[] field[i];   // Освобождаем строки field
//         delete[] opened[i];  // Освобождаем строки opened
//     }
//     delete[] field;   // Освобождаем массив указателей field
//     delete[] opened;  // Освобождаем массив указателей opened
    
//     return 0;  // Выход из программы
//     }
    
#include <SFML/Graphics.hpp>
#include <ctime>

using namespace sf;
const int CELL_SIZE = 25;
const int n = 9;
const int m = 9;
const int mines = 10;
int to_win = m * n - mines;
bool start = true;
int flag = 0; // 0 - игра, -1 - проигрыш, -2 - победа
int flags = mines;
int star = 0;
int tim = 0;

void init(int** field, int x, int y) {
    int coun = 0;
    int seed = time(0);
    srand(seed);
    flags = mines;
    to_win = m * n - mines;
    
    while(coun < mines) {
        int y_mina = rand() % n;
        int x_mina = rand() % m;
        
        if(abs(y - y_mina) + abs(x - x_mina) > 3 && field[y_mina][x_mina] != -1) {
            field[y_mina][x_mina] = -1;
            
            if(y_mina != 0 && field[y_mina-1][x_mina] != -1) field[y_mina-1][x_mina]++;
            if(y_mina != n-1 && field[y_mina+1][x_mina] != -1) field[y_mina+1][x_mina]++;
            if(x_mina != 0 && field[y_mina][x_mina-1] != -1) field[y_mina][x_mina-1]++;
            if(x_mina != m-1 && field[y_mina][x_mina+1] != -1) field[y_mina][x_mina+1]++;
            
            if(y_mina != 0 && x_mina != 0 && field[y_mina-1][x_mina-1] != -1) field[y_mina-1][x_mina-1]++;
            if(y_mina != n-1 && x_mina != 0 && field[y_mina+1][x_mina-1] != -1) field[y_mina+1][x_mina-1]++;
            if(y_mina != n-1 && x_mina != m-1 && field[y_mina+1][x_mina+1] != -1) field[y_mina+1][x_mina+1]++;
            if(y_mina != 0 && x_mina != m-1 && field[y_mina-1][x_mina+1] != -1) field[y_mina-1][x_mina+1]++;
            
            coun++;
        }
    }
    star = time(0);
    tim = 0;
}

bool openfild(int** field, int** opened, int y_mina, int x_mina) {
    if(y_mina >= n || y_mina < 0 || x_mina >= m || x_mina < 0) return false;
    
    if (opened[y_mina][x_mina] == 0) {
        opened[y_mina][x_mina] = 1;
        to_win--;
    }
    
    if(field[y_mina][x_mina] == 0) {
        if(y_mina != 0 && opened[y_mina-1][x_mina] == 0) openfild(field, opened, y_mina-1, x_mina);
        if(y_mina != n-1 && opened[y_mina+1][x_mina] == 0) openfild(field, opened, y_mina+1, x_mina);
        if(x_mina != 0 && opened[y_mina][x_mina-1] == 0) openfild(field, opened, y_mina, x_mina-1);
        if(x_mina != m-1 && opened[y_mina][x_mina+1] == 0) openfild(field, opened, y_mina, x_mina+1);
        
        if(y_mina != 0 && x_mina != 0 && opened[y_mina-1][x_mina-1] == 0) openfild(field, opened, y_mina-1, x_mina-1);
        if(y_mina != n-1 && x_mina != 0 && opened[y_mina+1][x_mina-1] == 0) openfild(field, opened, y_mina+1, x_mina-1);
        if(y_mina != n-1 && x_mina != m-1 && opened[y_mina+1][x_mina+1] == 0) openfild(field, opened, y_mina+1, x_mina+1);
        if(y_mina != 0 && x_mina != m-1 && opened[y_mina-1][x_mina+1] == 0) openfild(field, opened, y_mina-1, x_mina+1);
    }
    return true;
}

int main() {
    VideoMode vid;
    vid.width = CELL_SIZE * (m + 2);
    vid.height = CELL_SIZE * (n + 4);
    RenderWindow window(vid, "Minesweeper 9x9", Style::Default);
    
    Texture but;
    but.loadFromFile("buttens (2).png");
    Texture num;
    num.loadFromFile("numbers (2).png");
    Texture text;
    text.loadFromFile("Text (2).png");
    Texture smile;
    smile.loadFromFile("emodjy.png");
    srand(time(NULL));
    
    RectangleShape cell(Vector2f(CELL_SIZE, CELL_SIZE));
    cell.setTexture(&but);
    cell.setTextureRect(IntRect(0, 0, 25, 25));
    
    RectangleShape number(Vector2f(20, 35.5));
    number.setTexture(&num);
    number.setTextureRect(IntRect(0, 0, 20, 35.4));
    
    RectangleShape textbox(Vector2f(158, 86));
    textbox.setTexture(&text);

    RectangleShape smiley(Vector2f(25, 25));
    smiley.setTexture(&smile);
    
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
    
    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
            }
            
            if (event.type == Event::MouseButtonPressed) {
                Vector2i pos = Mouse::getPosition(window);
                int x = pos.x;
                int y = pos.y;
                
                if (event.mouseButton.button == Mouse::Left) {
                    // Проверка клика по смайлику
                    int smileyX = (25 * (m + 2)) / 2 - 12;
                    int smileyY = 25;
                    
                    if (x >= smileyX && x <= smileyX + 25 && 
                        y >= smileyY && y <= smileyY + 25) {
                        // Перезапуск игры
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
                    
                    // Обработка клика по игровому полю
                    if (y < 25*(n+3) && x < 25*(m+1) && y > 75 && x > 25) {
                        int cellY = (y - 75) / 25;
                        int cellX = (x - 25) / 25;
                        
                        if (opened[cellY][cellX] == 0) {
                            if (start) {
                                init(field, cellY, cellX);
                            }
                            openfild(field, opened, cellY, cellX);
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
        
        window.clear(Color(96, 96, 96));
        
        if(to_win == 0 && flag == 0) flag = -2;
        
        int window_width = 25 * (m + 2);
        int text_width = 158;
        int center_x = (window_width - text_width) / 2;
        
        if(flag == -2) {
            textbox.setPosition(center_x, 25);
            textbox.setTextureRect(IntRect(0, 0, 158, 43));
            window.draw(textbox);
        }
        
        if(flag == -1) {
            textbox.setPosition(center_x, 25);
            textbox.setTextureRect(IntRect(0, 43, 158, 43));
            window.draw(textbox);
        }
        
        // Счетчик флагов
        number.setPosition(30, 25);
        number.setTextureRect(IntRect(0, (11-flags/100)*35.5, 20, 35.5));
        window.draw(number);
        number.move(20, 0);
        number.setTextureRect(IntRect(0, (11-(flags%100)/10)*35.5, 20, 35.5));
        window.draw(number);
        number.move(20, 0);
        number.setTextureRect(IntRect(0, (11-(flags%10))*35.5, 20, 35.5));
        window.draw(number);
        
        // Таймер
        if (star > 0 && flag == 0) tim = (time(0) - star);
        number.setPosition(25*(m+2) - 50, 25);
        number.setTextureRect(IntRect(0, (11-(tim%10))*35.5, 20, 35.5));
        window.draw(number);
        number.move(-20, 0);
        number.setTextureRect(IntRect(0, (11-(tim%60)/10)*35.5, 20, 35.5));
        window.draw(number);
        number.move(-20, 0);
        number.setTextureRect(IntRect(0, (11-(tim/60))*35.5, 20, 35.5));
        window.draw(number);
        
        // Смайлик (исправлены состояния)
        if(flag == 0) {
            smiley.setTextureRect(IntRect(0, 25, 25, 25)); // обычный
        } else if(flag == -1) {
            smiley.setTextureRect(IntRect(0, 50, 25, 25)); // проиграл
        } else if(flag == -2) {
            smiley.setTextureRect(IntRect(0, 0, 25, 25)); // выиграл
        }
        smiley.setPosition((window_width - 25) / 2, 25); // точное центрирование
        window.draw(smiley);
        
        // Игровое поле
        for(int j = 0; j < n; j++) {
            for(int i = 0; i < m; i++) {
                cell.setPosition(25+25*i, 75 + 25*j);
                
                if(opened[j][i] == 0) {
                    cell.setTextureRect(IntRect(0, 0, 25, 25));
                    window.draw(cell);
                }
                if(opened[j][i] == -1) {
                    cell.setTextureRect(IntRect(0, 25, 25, 25));
                    window.draw(cell);
                }
                if(opened[j][i] == 1) {
                    if(field[j][i] == -1) cell.setTextureRect(IntRect(0, 125, 25, 25));
                    else if(field[j][i] == -2) cell.setTextureRect(IntRect(0, 75, 25, 25));
                    else if(field[j][i] == -3) cell.setTextureRect(IntRect(0, 100, 25, 25));
                    else cell.setTextureRect(IntRect(0, 25*(15-field[j][i]), 25, 25));
                    window.draw(cell);
                }
            }
        }
        
        window.display();
    }
    
    for (int i = 0; i < n; i++) {
        delete[] field[i];
        delete[] opened[i];
    }
    delete[] field;
    delete[] opened;
    
    return 0;
}