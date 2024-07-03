#include <iostream>
#include <string>

using namespace std;

struct DataSensor {
    string namaSensor;
    double nilaiSensor;
    string waktuPantau;

    DataSensor* next;
    DataSensor* prev;
};

DataSensor* head = NULL;
DataSensor* tail = NULL;
const int maks = 5;

int count() {
    if (head == NULL) {
        return 0;
    } else {
        int banyak = 0;
        DataSensor* current = head;
        while (current != NULL) {
            current = current->next;
            banyak++;
        }
        return banyak;
    }
}

bool fullKah() {
    return count() == maks;
}

bool kosongKah() {
    return count() == 0;
}

void add(string nama, double sensor, string waktu) {
    if (fullKah()) {
        cout << "Full" << endl;
    } else {
        DataSensor* newNode = new DataSensor;
        newNode->namaSensor = nama;
        newNode->nilaiSensor = sensor;
        newNode->waktuPantau = waktu;
        newNode->next = NULL;

        if (kosongKah()) {
            newNode->prev = NULL;
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }
}

void hapus() {
    if (tail == NULL) {
        cout << "Kosong" << endl;
        return;
    }
    DataSensor* delt = tail;
    tail = tail->prev;
    if (tail != NULL) {
        tail->next = NULL;
    } else {
        head = NULL;
    }
    delete delt;
}

void print() {
    if (head == NULL) {
        cout << "Kosong" << endl;
    } else {
        cout << "Data Sensor" << endl;
        DataSensor* current = tail;
        while (current != NULL) {
            cout << "Nama Sensor: " << current->namaSensor << " - " << current->nilaiSensor << " - " << current->waktuPantau << endl;
            cout << endl;
            current = current->prev;
        }
    }
}

void peek(int posisi) {
    if (head == NULL) {
        cout << "Kosong" << endl;
    } else {
        int nomor = 1;
        DataSensor* current = tail;
        while (nomor < posisi && current != NULL) {
            current = current->prev;
            nomor++;
        }
        if (current != NULL) {
            cout << "Data ke-" << posisi << " Nama Sensor: " << current->namaSensor << " - " << current->nilaiSensor << " - " << current->waktuPantau << endl;
        } else {
            cout << "Posisi tidak valid" << endl;
        }
    }
}

void change(string nama, double sensor, string waktu, int posisi) {
    if (kosongKah()) {
        cout << "Kosong" << endl;
    } else {
        int nomor = 1;
        DataSensor* current = tail;
        while (nomor < posisi && current != NULL) {
            current = current->prev;
            nomor++;
        }
        if (current != NULL) {
            current->namaSensor = nama;
            current->nilaiSensor = sensor;
            current->waktuPantau = waktu;
        } else {
            cout << "Posisi tidak valid" << endl;
        }
    }
}

void destroy() {
    DataSensor* current = head;
    while (current != NULL) {
        DataSensor* delt = current;
        current = current->next;
        delete delt;
    }
    head = NULL;
    tail = NULL;
}

int main() {
    add("Sensor A", 80, "3 Jam");
    add("Sensor B", 70, "2 Jam");
    cout << "Apakah data penuh? " << fullKah() << endl;
    cout << "Apakah data kosong? " << kosongKah() << endl;

    //destroy();
    add("Sensor C", 90, "1 Jam");
    add("Sensor D", 98, "10 Jam");
    peek(2);
    change("Sensor E", 404, "12 Jam", 90);

    print();

    return 0;
}
