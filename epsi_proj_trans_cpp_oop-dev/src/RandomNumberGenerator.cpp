//
// Created by Killian on 14/03/2023.
//
#include <RandomNumberGenerator.h>
#include <functional>

std::mt19937 RandomNumberGenerator::s_generator; // NOLINT

void RandomNumberGenerator::Init()
{
    std::seed_seq seed = GenerateRandomSeed();
    s_generator.seed(seed);
}

int RandomNumberGenerator::GetRandomInt(int min, int max)
{
    std::uniform_int_distribution<int> distribution(min, max);
    return distribution(s_generator);
}

float RandomNumberGenerator::GetRandomFloat(float min, float max)
{
    std::uniform_real_distribution<float> distribution(min, max);
    return distribution(s_generator);
}

double RandomNumberGenerator::GetRandomDouble(double min, double max)
{
    std::uniform_real_distribution<double> distribution(min, max);
    return distribution(s_generator);
}

std::seed_seq RandomNumberGenerator::GenerateRandomSeed()
{
    std::random_device device;

    uint32_t seed_data[std::mt19937::state_size];
    std::generate(std::begin(seed_data), std::end(seed_data), std::ref(device));

    return std::seed_seq(std::begin(seed_data), std::end(seed_data)); // NOLINT
}