//
// Created by JoachimWagner on 10.04.2024.
//

#pragma once
#include <iostream>
#include "../../VectorFactory.h"
#include "../sequential/VectorFactorySequentialImpl.h"

#include "../decorators/VectorFactoryBenchmarkDecorator.h"

#include "../../../generator/Generator.h"
#include "../../../time/impl/StopwatchImpl.h"

namespace atlas::collection {
    template<class T>
    class VectorFactoryBuilder {

        using VECTOR_FACTORY = std::unique_ptr<atlas::collection::VectorFactory<int>>;
        using VECTOR_FACTORY_SEQUENCIAL = atlas::collection::VectorFactorySequentialImpl<int>;


        using VECTOR_FACTORY_BENCHMARK = atlas::collection::VectorFactoryBenchmarkDecorator<int>;

        using GENERATOR = std::unique_ptr<generator::Generator<int>>;

        inline static bool benchmark{false};


    public:
        static bool isBenchmark() {
            return benchmark;
        }

        static void setBenchmark(bool benchmark) {
            VectorFactoryBuilder::benchmark = benchmark;
        }


        static VECTOR_FACTORY createWithGenerator(GENERATOR generator) {
            VECTOR_FACTORY result;

            result = std::make_unique<VECTOR_FACTORY_SEQUENCIAL>(std::move(generator));
            if(benchmark) result = std::make_unique<VECTOR_FACTORY_BENCHMARK>(std::move(result), std::make_unique<atlas::time::StopwatchImpl>());
            return result;
        }
    };
}
