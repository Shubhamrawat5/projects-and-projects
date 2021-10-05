import { Component, OnInit } from '@angular/core';
import { Customer } from '../customer';
import { CustomerService } from '../customer.service';
import { HttpErrorResponse } from '@angular/common/http';
import { NgForm } from '@angular/forms';
@Component({
  selector: 'app-add-one',
  templateUrl: './add-one.component.html',
  styleUrls: ['./add-one.component.css']
})
export class AddOneComponent implements OnInit {
  public customer!: Customer;
  public view!:string;
  constructor(private customerService:CustomerService) { }

  ngOnInit(): void {
  }

  public onAddCustomer(addForm: NgForm): void {
    this.customerService.addEmployee(addForm.value).subscribe(
      (response: Customer) => {
        console.log(response);
        this.view="yes";
      },
      (error: HttpErrorResponse) => {
        alert(error.message);
        addForm.reset();
      }
    );
  }

}
