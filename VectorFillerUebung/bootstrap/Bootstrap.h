//
// Created by JoachimWagner on 10.04.2024.
//

#pragma once
#include <iostream>
#include <memory>
#include <thread>
#include "../generator/impl/random/MersenneTwisterNumberGenerator.h"
#include "../collections/impl/builder/VectorFactoryBuilder.h"
#include "../client/impl/ClientImpl.h"


namespace atlas::bootstrap {
    class Bootstrap {
        using VECTOR_FACTORY = std::unique_ptr<atlas::collection::VectorFactory<int>>;

        using GENERATOR = std::unique_ptr<generator::Generator<int>>;
        using CLIENT = std::unique_ptr<atlas::client::Client>;

        static void create(size_t threadCount) {

            auto generator = createGenerator();
            atlas::collection::VectorFactoryBuilder<int>::setBenchmark(true);
            auto vectorFiller = atlas::collection::VectorFactoryBuilder<int>::createWithGenerator(std::move(generator));
            auto client = createClient(std::move(vectorFiller));

            client->doSomethingWithLargeVector();
        }

        static GENERATOR createGenerator() {
            GENERATOR generator = std::make_unique<atlas::generator::MersenneTwisterNumberGenerator>();
            return generator;
        }


        static CLIENT createClient(VECTOR_FACTORY factory) {
            CLIENT client = std::make_unique<atlas::client::VectorClientImpl>(std::move(factory));
            return client;
        }



    public:


        auto startApplication()-> void const {
            /*const size_t availableProcessors = std::thread::hardware_concurrency();
            for (int threadCount = 0; threadCount <= availableProcessors + 1; ++threadCount) {
                std::cout << "Starte Messung mit " << threadCount << " Threads" << std::endl;
                create(threadCount);
            }
            */
            create(1);
        }

    };
}
