#ifndef MATRIX_TRACE_TPP
#define MATRIX_TRACE_TPP

template<typename T, std::size_t M, std::size_t N>
T Matrix<T, M, N>::trace() const requires (M == N) {
    T trace = T();

    for (std::size_t i = 0; i < M; ++i) {
        trace += (*this)[i][i];
    }

    return trace;
}

#endif // MATRIX_TRACE_TPP
