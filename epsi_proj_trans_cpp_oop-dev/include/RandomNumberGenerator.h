//
// Created by Killian on 14/03/2023.
//

#pragma once

#include <random>

////////////////////////////////////////////////////////////
/// \brief  A utility class that creates random numbers
///
/// This class is capable of generating random integers, float
/// and doubles using the uniform distributions and the mt19937
/// engine
///
/// This class needs to be initialized with
/// RandomNumberGenerator::Init()
///
/// \see RandomNumberGenerator::Init()
////////////////////////////////////////////////////////////
class RandomNumberGenerator
{
public:
    RandomNumberGenerator() = delete;

    ////////////////////////////////////////////////////////////
    /// \brief  Initializes the random engine
    ///
    /// This should be called before other methods in order to seed
    /// the engine randomly, and avoid predictable randomness
    ///
    ////////////////////////////////////////////////////////////
    static void Init();

    ////////////////////////////////////////////////////////////
    /// \brief  Generates a random 32-bit integer
    ///
    /// The generated integer is guaranteed to be between
    /// min and max
    ///
    /// \param min The minimum integer
    /// \param max The maximum integer
    /// \return A randomly generated number between min and max
    ///
    ////////////////////////////////////////////////////////////
    static int32_t GetRandomInt(int32_t min, int32_t max);

    ////////////////////////////////////////////////////////////
    /// \brief  Generates a random 32-bit float
    ///
    /// The generated float is guaranteed to be between
    /// min and max
    ///
    /// \param min The minimum integer
    /// \param max The maximum integer
    /// \return A randomly generated decimal between min and max
    ///
    ////////////////////////////////////////////////////////////
    static float GetRandomFloat(float min, float max);

    ////////////////////////////////////////////////////////////
    /// \brief  Generates a random 64-bit double
    ///
    /// The generated double is guaranteed to be between
    /// min and max
    ///
    /// \param min The minimum integer
    /// \param max The maximum integer
    /// \return A randomly generated decimal between min and max
    ///
    ////////////////////////////////////////////////////////////
    static double GetRandomDouble(double min, double max);

private:
    ////////////////////////////////////////////////////////////
    /// \brief  Generates a random seed to be used in the
    ///         initialization of the random engine
    ///
    ////////////////////////////////////////////////////////////
    static std::seed_seq GenerateRandomSeed();

    static std::mt19937 s_generator;
};
