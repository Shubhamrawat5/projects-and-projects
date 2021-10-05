package com.Harsh.FullStackTry.repositry;

import org.springframework.data.jpa.repository.JpaRepository;

import com.Harsh.FullStackTry.model.Customer;

public interface custRepo extends JpaRepository<Customer,Long>{

}
