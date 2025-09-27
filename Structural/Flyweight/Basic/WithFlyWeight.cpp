#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>
using namespace std;

// Flyweight - stores shared (intrinsic) state
class AsteroidFlyweight {
private:
    int length, width, weight;
    string color, texture, material;

public:
    AsteroidFlyweight(int l, int w, int wt, string col, string tex, string mat) {
        this->length = l;
        this->width = w;
        this->weight = wt; // ✅ Fixed: was incorrectly assigned before
        this->color = col;
        this->texture = tex;
        this->material = mat;
    }

    void render(int posX, int posY, int velocityX, int velocityY) {
        cout << "Rendering " << color << ", " << texture << ", " << material
             << " asteroid at (" << posX << "," << posY
             << ") Size: " << length << "x" << width
             << " Velocity: (" << velocityX << "," << velocityY << ")\n";
    }

    static size_t getMemoryUsage() {
        return sizeof(int) * 3 + sizeof(string) * 3 + 32 * 3;
    }
};

// Factory to manage and reuse flyweights
class AsteroidFactory {
private:
    static unordered_map<string, AsteroidFlyweight*> flyweights;

public:
    static AsteroidFlyweight* getAsteroid(int length, int width, int weight,
                                          const string& color,
                                          const string& texture,
                                          const string& material) {
        string key = to_string(length) + "_" + to_string(width) + "_" + to_string(weight) + "_" +
                     color + "_" + texture + "_" + material;

        if (flyweights.find(key) == flyweights.end()) {
            flyweights[key] = new AsteroidFlyweight(length, width, weight, color, texture, material);
        }

        return flyweights[key];
    }

    static int getFlyweightCount() {
        return flyweights.size();
    }

    static size_t getTotalFlyweightMemory() {
        return flyweights.size() * AsteroidFlyweight::getMemoryUsage();
    }

    static void cleanup() {
        for (auto& pair : flyweights) {
            delete pair.second;
        }
        flyweights.clear();
    }
};

// Define static member
unordered_map<string, AsteroidFlyweight*> AsteroidFactory::flyweights;


// Context - holds unique (extrinsic) state
class AsteroidContext {
private:
    AsteroidFlyweight* flyweight;
    int posX, posY;
    int velocityX, velocityY;

public:
    AsteroidContext(AsteroidFlyweight* fw, int posX, int posY, int velX, int velY) {
        this->flyweight = fw;
        this->posX = posX;
        this->posY = posY;
        this->velocityX = velX;
        this->velocityY = velY;
    }

    void render() {
        flyweight->render(posX, posY, velocityX, velocityY);
    }

    static size_t getMemoryUsage() {
        return sizeof(AsteroidFlyweight*) + sizeof(int) * 4;
    }
};

// Game class that manages all asteroids
class SpaceGameWithFlyweight {
private:
    vector<AsteroidContext*> asteroids;

public:
    void spawnAsteroids(int count) {
        cout << "\n=== Spawning " << count << " asteroids ===" << endl;

        vector<string> colors = {"Red", "Blue", "Gray"};
        vector<string> textures = {"Rocky", "Metallic", "Icy"};
        vector<string> materials = {"Iron", "Stone", "Ice"};
        int sizes[] = {25, 35, 45};

        for (int i = 0; i < count; ++i) {
            int type = i % 3;

            AsteroidFlyweight* flyweight = AsteroidFactory::getAsteroid(
                sizes[type], sizes[type], sizes[type] * 10,
                colors[type], textures[type], materials[type]
            );

            asteroids.push_back(new AsteroidContext(
                flyweight,
                100 + i * 50,
                200 + i * 30,
                1,
                2
            ));
        }

        cout << "Created " << asteroids.size() << " asteroid contexts" << endl;
        cout << "Total flyweight objects: " << AsteroidFactory::getFlyweightCount() << endl;
    }

    void renderAll() {
        cout << "\n--- Rendering first 5 asteroids ---" << endl;
        for (int i = 0; i < min(5, (int)asteroids.size()); ++i) {
            asteroids[i]->render();
        }
    }

    size_t calculateMemoryUsage() {
        size_t contextMemory = asteroids.size() * AsteroidContext::getMemoryUsage();
        size_t flyweightMemory = AsteroidFactory::getTotalFlyweightMemory();
        return contextMemory + flyweightMemory;
    }

    int getAsteroidCount() {
        return asteroids.size();
    }

    ~SpaceGameWithFlyweight() {
        // ✅ Clean up dynamically allocated contexts
        for (auto ptr : asteroids) {
            delete ptr;
        }
        asteroids.clear();
    }
};

// === MAIN ===
//int main() {
//    const int ASTEROID_COUNT = 1000000;
//
//    cout << "\nTESTING WITH FLYWEIGHT PATTERN" << endl;
//    SpaceGameWithFlyweight* game = new SpaceGameWithFlyweight();
//
//    game->spawnAsteroids(ASTEROID_COUNT);
//
//    game->renderAll();
//
//    size_t totalMemory = game->calculateMemoryUsage();
//
//    cout << "\n=== MEMORY USAGE ===" << endl;
//    cout << "Total asteroids: " << ASTEROID_COUNT << endl;
//    cout << "Memory per asteroid: " << AsteroidContext::getMemoryUsage() << " bytes" << endl;
//    cout << "Total memory used: " << totalMemory << " bytes" << endl;
//    cout << "Memory in MB: " << totalMemory / (1024.0 * 1024.0) << " MB" << endl;
//
//    delete game;
//
//    // ✅ Cleanup flyweights to avoid memory leak
//    AsteroidFactory::cleanup();
//
//    return 0;
//}
