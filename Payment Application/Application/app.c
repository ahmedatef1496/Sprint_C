#include"app.h"

void userStory(void)
{
	ST_cardData_t cardData;
	ST_terminalData_t termData;
	ST_transaction_t transData;

	float maxAmount = 0;
	/*0- Setting max amount*/
	printf("Set Max Amount of Transactions\n");
	scanf("%f", &maxAmount);
	while(setMaxAmount(&termData, maxAmount))
	{
		printf("Wrong Input\n");
		printf("Set Max Amount of Transactions\n");
		scanf("%f", &maxAmount);
	}
	fflush(stdin);
	
	
		while (1)
		{	
			/*1- Get card holder name*/
			while (getCardHolderName(&cardData))
				printf("Wrong Card Holder Name\n");

			/*2- Get card expiration date*/
			while (getCardExpiryData(&cardData))
				printf("Wrong Expiration Date\n");


			/*3- Get card PAN*/
			while (getCardPAN(&cardData))
				printf("Wrong Primary Account Number\n");

			/*4- Get All card data*/
			strcpy(transData.cardHolderData.cardHolderName, cardData.cardHolderName);
			strcpy(transData.cardHolderData.cardExpirationData, cardData.cardExpirationData);
			strcpy(transData.cardHolderData.primaryAcountNumber, cardData.primaryAcountNumber);

			/*5- Get transaction date*/
			printf("Enter transaction Date in format DD/MM/YYYY\n");
			gets(&termData.transactionDate);
			while (getTransactionDate(&termData))
			{
				printf("Wrong Date, Enter Again\n");
				gets(&termData.transactionDate);
			}

			/*6- is Card Expired?*/
			if (isCardExpired(&cardData, &termData))
			{
				/*7.True- Decline Expired Card*/
				printf("Card is Expired\n");
			}
			else
			{
				/*7.False- Get transaction amount*/
				printf("Enter transaction amount\n");
				scanf("%f", &termData.transAmount);
				while (getTransactionAmount(&termData))
				{
					printf("Invalid amount, enter agian\n");
					scanf("%f", &termData.transAmount);
				}
				/*8- is Exceeded amount?*/
				if (isBelowMaxAmount(&termData))
				{
					/*8.True- Decline amount exceeding limit*/
					printf("Transaction Amount Exceeding Limit\n");
				}
				else
				{

					strcpy(transData.terminalData.transactionDate, termData.transactionDate);
					transData.terminalData.transAmount = termData.transAmount;
					
					recieveTransactionData(&transData);
				}


			}
			printf("\n.\n.\n.\n.");
		}
}